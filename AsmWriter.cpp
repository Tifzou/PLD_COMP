//
// Created by halunka on 26/03/19.
//

#include "AsmWriter.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

void AsmWriter::setNomFichierInput(string nom){
    inFile=nom;
}

void AsmWriter::setNomFichierOutput(string nom){
    outFile=nom;
}

bool AsmWriter::convert(){
    size_t foundCpp=inFile.find(".cpp",0);
    if (foundCpp!=std::string::npos){
        inFile.replace(inFile.end()-4,inFile.end(),".asm");
        cout<<"Okay, .cpp rules"<<endl;
    }else{
        size_t foundC=inFile.find(".c",0);
        if (foundC!=std::string::npos){
            cout<<"Okay, .c rules"<<endl;
            inFile.replace(inFile.end()-2,inFile.end(),".s");
        }else{
            cerr<<"Le fichier d'entrée n'a pas la bonne extension !\n";
            return 0;
        }
    }
    return 1;
}

bool AsmWriter::writeOutputFile(matrice resultat) {
    ofstream myfile (outFile);
    if (myfile.is_open()){
        myfile << ".text\n";
        myfile << ".global main\n";
        myfile << "main:\n";
        myfile << "\tpushq\t%rbp"<<endl;
        myfile << "\tmovq\t%rsp, %rbp"<<endl;
        int stackPtr = 0;
        vector<Commande>::iterator itInstr;
        for(itInstr = resultat.begin() ; itInstr != resultat.end() ; ++itInstr)
        {
            switch ((*itInstr).type) // {ERR, WARN, VAR_DEC, VAR_DEF, OPER, RET, AFF};
            {
                case 0 : // ERR
                    cerr << "in case ERR" << endl;
                    break;
                case 1 : // WAR
                    cerr << "in case WAR" << endl;
                    break;
                case 2 : // VAR DECLARATION
                    cerr << "in case VAR_DEC" << endl;
                    writeDec((*itInstr));
                    break;
                case 3 : // VAR DEFINITION
                    cerr << "in case VAR_DEF" << endl;
                    myfile << writeDef((*itInstr));
                    break;
                case 4 : // OPER
                    cerr << "in case OPER" << endl;
                    if((*itInstr).elements.size() == 3)
                    {
                        myfile << writeDef((*itInstr));
                    }
                    else if((*itInstr).elements.size() == 5)
                    {
                        myfile << writeOperation((*itInstr));
                    }
                    break;
                case 5 : // RET
                    cerr << "in case RET" << endl;
                    myfile << writeReturn((*itInstr));
                    break;
                case 6: // AFFECTATION
                    cerr << "in case AFF" << endl;
                    myfile << writeAff((*itInstr));
                    break;
                case 7: // IF
                    cerr << "in case IF" << endl;
                    myfile << writeIf((*itInstr));
                    break;
                case 8: //Predicat (bloc)
                    cerr << "in case Predicat" << endl;

                    for(string s : writePredicat((*itInstr))){
                        myfile << s;
                    }
                    break;
                default:
                    break;
            }
        }

        myfile << "\tpopq	%rbp"<<endl;
        myfile << "\tret"<<endl;
        myfile.close();
        return 0;
    }else{
        cerr << "Unable to create .s file !"<< endl;
        return 1;
    }
}

string AsmWriter::writeReturn(Commande returnCmd)
{
    string nomVar = returnCmd.elements[0];
    map<string, string>::iterator it = variables.find(nomVar);
    string address;
    if (it != variables.end())
    {
        address = it->second;
    }
    else
    {
        address = "$"+nomVar;
    }
    string asmInstr = "\tmovl\t"+address+", %eax\n";
    return asmInstr;
}

string AsmWriter::writeAff(Commande affectationCmd)
{
    string nomVar = affectationCmd.elements[1];
    string valVar = affectationCmd.elements[2];

    map<string, string>::iterator it = variables.find(nomVar);
    string address = it->second;

    it = variables.find(valVar);
    string asmInstr;
    if (it != variables.end())
    {
        valVar = it->second;
        asmInstr = "\tmovl\t"+valVar+", %eax\n";
        asmInstr += "\tmovl\t%eax, "+address+"\n";
    }
    else
    {
        valVar = "$"+valVar;
        asmInstr = "\tmovl\t"+valVar+", "+address+"\n";
    }


    return asmInstr;
}

void AsmWriter::writeDec(Commande declarationCmd)
{
    string varName = declarationCmd.elements[1];
    int stackPos = (variables.size()+1) * (-4);
    string varAddress = to_string(stackPos) + "(%rbp)";
    variables.insert(make_pair(varName, varAddress));
}

string AsmWriter::writeDef(Commande definitionCmd)
{
    writeDec(definitionCmd);
    string asmInstr = writeAff(definitionCmd);
    return asmInstr;
}

string AsmWriter::writeOperation(Commande operationCmd)
{
    if (operationCmd.elements[3] == "*")
    {
        return writeMult(operationCmd);
    }
    else if(operationCmd.elements[3] == "+") {
        return writeAdd(operationCmd);
    }
    else if(operationCmd.elements[3] == "-") {
        return writeSub(operationCmd);
    }
    else
    {
        return "unknown operation"; // TODO: appeler une erreur
    }
}

string AsmWriter::writeAdd(Commande additionCmd)
{
    map<string, string>::iterator it;

    string varResultat = additionCmd.elements[1];
    it = variables.find(varResultat);
    if (it == variables.end())
    {
        Commande dec;
        dec.type = commandeType::VAR_DEC;
        dec.elements.push_back("int");
        dec.elements.push_back(varResultat);
        writeDec(dec);
        it = variables.find(varResultat);
    }
    string addressRes = it->second;

    string varOp1 = additionCmd.elements[2];
    string addressOp1;
    it = variables.find(varOp1);
    if (it != variables.end())
    {
        addressOp1 = it->second;
    }
    else
    {
        addressOp1 = "$"+varOp1;
    }

    string varOp2 = additionCmd.elements[4];
    string addressOp2;
    it = variables.find(varOp2);
    if (it != variables.end())
    {
        addressOp2 = it->second;
    }
    else
    {
        addressOp2 = "$"+varOp2;
    }

    string asmInstr = "\tmovl\t"+addressOp1+", %edx\n";
    asmInstr += "\tmovl\t"+addressOp2+", %eax\n";
    asmInstr += "\taddl\t%edx, %eax\n";
    asmInstr += "\tmovl\t %eax, "+addressRes+"\n";

    return asmInstr;
}

string AsmWriter::writeSub(Commande substractionCmd)
{
    cout << "yeah for substraction" << endl;
    map<string, string>::iterator it;

    string varResultat = substractionCmd.elements[1];
    it = variables.find(varResultat);
    if (it == variables.end())
    {
        Commande dec;
        dec.type = commandeType::VAR_DEC;
        dec.elements.push_back("int");
        dec.elements.push_back(varResultat);
        writeDec(dec);
        it = variables.find(varResultat);
    }
    string addressRes = it->second;

    string varOp1 = substractionCmd.elements[2];
    it = variables.find(varOp1);
    string addressOp1;
    if (it != variables.end())
    {
        addressOp1 = it->second;
    }
    else
    {
        addressOp1 = "$"+varOp1;
    }

    string varOp2 = substractionCmd.elements[4];
    it = variables.find(varOp2);
    string addressOp2;
    if (it != variables.end())
    {
        addressOp2 = it->second;
    }
    else
    {
        addressOp2 = "$"+varOp2;
    }

    string asmInstr = "\tmovl\t"+addressOp1+", %eax\n";
    asmInstr += "\tmovl\t"+addressOp2+", %edx\n";
    asmInstr += "\tsubl\t%edx, %eax\n";
    asmInstr += "\tmovl\t %eax, "+addressRes+"\n";

    return asmInstr;
}

string AsmWriter::writeMult(Commande multiplicationCmd)
{
    map<string, string>::iterator it;

    string varResultat = multiplicationCmd.elements[1];
    it = variables.find(varResultat);
    if (it == variables.end())
    {
        Commande dec;
        dec.type = commandeType::VAR_DEC;
        dec.elements.push_back("int");
        dec.elements.push_back(varResultat);
        writeDec(dec);
        it = variables.find(varResultat);
    }
    string addressRes = it->second;

    string varOp1 = multiplicationCmd.elements[2];
    it = variables.find(varOp1);
    string addressOp1;
    if (it != variables.end())
    {
        addressOp1 = it->second;
    }
    else
    {
        addressOp1 = "$"+varOp1;
    }

    string varOp2 = multiplicationCmd.elements[4];
    it = variables.find(varOp2);
    string addressOp2;
    if (it != variables.end())
    {
        addressOp2 = it->second;
    }
    else
    {
        addressOp2 = "$"+varOp2;
    }

    string asmInstr = "\tmovl\t"+addressOp1+", %edx\n";
    asmInstr += "\tmovl\t"+addressOp2+", %eax\n";
    asmInstr += "\timull\t%edx, %eax\n";
    asmInstr += "\tmovl\t %eax, "+addressRes+"\n";

    return asmInstr;
}


string AsmWriter::writeIf(Commande ifCmd)
{
    string flagIf = "if"+std::to_string(flagCounter);
    namespaceFlags.push_back(flagIf);
    flagIf+=":\n";
    return flagIf;

}

void AsmWriter::printVariableMap()
{
    map<string, string>::iterator it;
    for (it = variables.begin() ; it != variables.end() ; ++it)
    {
        cout << it->first << " @" << it->second << endl;
    }
}

vector<string> AsmWriter::writePredicat(Commande returnCmd)
{
    map<string, string>::iterator it;
    vector<string> cmp;
    if (returnCmd.elements[3] == "==")
    {
        it = variables.find(returnCmd.elements[2]);
        //TODO test si variable existe ==> it=variables.end()
        string addVar1 = it->second;

        it = variables.find(returnCmd.elements[4]);
        string addVar2 = it->second;

        string asmInstr = "\tmovl\t"+addVar1+", %edx\n";
        asmInstr += "\tmovl\t"+addVar2+", %eax\n";
        asmInstr += "\tcmpl\t%edx, %eax\n";
        cmp.push_back(asmInstr);
        //cmp.push_back("\tjne else\n");
    }
    else if (returnCmd.elements[3] == ">=")
    {
        cmp.push_back("cmpl\t" + returnCmd.elements[2] + " " + returnCmd.elements[4]);
        cmp.push_back("jb else");
    }
    else if (returnCmd.elements[3] == ">")
    {
        cmp.push_back("cmpl " + returnCmd.elements[2] + " " + returnCmd.elements[4]);
        cmp.push_back("jbe else");
    }
    else if (returnCmd.elements[3] == "<=")
    {
        cmp.push_back("cmpl " + returnCmd.elements[2] + " " + returnCmd.elements[4]);
        cmp.push_back("ja else");
    }
    else if (returnCmd.elements[3] == "<")
    {
        cmp.push_back("cmpl " + returnCmd.elements[2] + " " + returnCmd.elements[4]);
        cmp.push_back("jae else");
    }
    else if (returnCmd.elements[3] == "!=")
    {
        cmp.push_back("cmpl " + returnCmd.elements[2] + " " + returnCmd.elements[4]);
        cmp.push_back("je else");
    }

    return cmp;
}