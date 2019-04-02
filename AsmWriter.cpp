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
                    break;
                case 4 : // OPER
                    cerr << "in case OPER" << endl;
                    myfile << writeOperation((*itInstr));
                    break;
                case 5 : // RET
                    cerr << "in case RET" << endl;
                    myfile << writeReturn((*itInstr));
                    break;
                case 6: // AFFECTATION
                    cerr << "in case AFF" << endl;
                    myfile << writeAff((*itInstr));
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
    string address = it->second;
    string asmInstr = "\tmovl\t"+address+", %eax\n";
    return asmInstr;
}

string AsmWriter::writeAff(Commande affectationCmd)
{
    string nomVar = affectationCmd.elements[1];
    string valVar = affectationCmd.elements[2];

    map<string, string>::iterator it = variables.find(nomVar);
    string address = it->second;
    string asmInstr;
    try // definition
    {
        stoi(valVar);
        asmInstr = "\tmovl\t$"+valVar+", "+address+"\n";
    }
    catch (const invalid_argument& ia) // = autre variable
    {
        it = variables.find(nomVar);
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
    return writeSub(operationCmd); // TODO !!! 
}

string AsmWriter::writeAdd(Commande additionCmd)
{
    map<string, string>::iterator it;

    string varResultat = additionCmd.elements[0];
    it = variables.find(varResultat);
    string addressRes = it->second;

    string addition = additionCmd.elements[1];
    string varOp1 = addition.substr(0, addition.find("+"));
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

    string varOp2 = addition.substr(varOp1.size()+1, addition.size());
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

    string varResultat = substractionCmd.elements[0];
    it = variables.find(varResultat);
    string addressRes = it->second;

    string substraction = substractionCmd.elements[1];
    string varOp1 = substraction.substr(0, substraction.find("-"));
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

    string varOp2 = substraction.substr(varOp1.size()+1, substraction.size());
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

    string varResultat = multiplicationCmd.elements[0];
    it = variables.find(varResultat);
    string addressRes = it->second;

    string multiplication = multiplicationCmd.elements[1];
    string varOp1 = multiplication.substr(0, multiplication.find("*"));
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

    string varOp2 = multiplication.substr(varOp1.size()+1, multiplication.size());
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