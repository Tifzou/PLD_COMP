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


        int stackPtr = 0;
        vector<Commande>::iterator itInstr;
        for(itInstr = resultat.begin() ; itInstr != resultat.end() ; ++itInstr)
        {
            switch ((*itInstr).type) // {ERR, WARN, VAR_DEC, VAR_DEF, OPER, RET, AFF, FUNC, MAIN};
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
                case 9 : // FUNCTION
                    cerr << "in case FUNCTION" << endl;
                    myfile << writeFunc((*itInstr));
                    break;
                case 10: //MAIN
                    cerr << "in case MAIN" << endl;
                    myfile << "\t.global main\n";
                    myfile << "\t.type\t main, @function\n";
                    myfile << "main:\n";
                    myfile << "\tpushq\t%rbp"<<endl;
                    myfile << "\tmovq\t%rsp, %rbp"<<endl;
                    myfile << "\tsubq\t$16, %rsp" << endl;
                    break;
                case 11: // FUNC_CALL
                    cerr << "in case FUNCTION CALL" << endl;
                    myfile << writeFuncCall((*itInstr));
                    break;
                case 12: // FUNC_AFF
                    cerr << "in case FUNCTION AFF" << endl;
                    myfile << writeFuncAff((*itInstr));
                    break;
                default:
                    break;
            }
        }
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
    asmInstr += "\tmovq\t%rbp, %rsp\n";
    asmInstr += "\tpopq\t%rbp\n";
    asmInstr += "\tret\n";
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

string AsmWriter::writeFuncCall(Commande functionCmd)
{
    string funcName = functionCmd.elements[1];
    string asmInstr = "";
    for(int i=2 ; i<functionCmd.elements.size() ; i++)
    {
        string varName = functionCmd.elements[i];
        map<string, string>::iterator it = variables.find(varName);
        string varAddr;
        if (it != variables.end())
        {
            varAddr = it->second;
        }
        else
        {
            cout << "Houston, we have a problem (the variable doesn't exist" << endl;
        }
        asmInstr += "\tmov " + varAddr + ", " + paramRegister[i-2] + "\n";
    }
    asmInstr += "\tcall " + funcName + "\n";
    return asmInstr;
}

string AsmWriter::writeFuncAff(Commande functionCmd)
{
    string funcName = functionCmd.elements[1];
    string asmInstr = "";
    for(int i=2 ; i<functionCmd.elements.size() ; i++)
    {
        string varName = functionCmd.elements[i];
        map<string, string>::iterator it = variables.find(varName);
        string varAddr;
        if (it != variables.end())
        {
            varAddr = it->second;
        }
        else
        {
            cout << "Houston, we have a problem (the variable doesn't exist" << endl;
        }
        asmInstr += "\tmov " + varAddr + ", " + paramRegister[i-2] + "\n";
    }
    asmInstr += "\tcall " + funcName + "\n";
    map<string, string>::iterator it = variables.find(functionCmd.elements[1]);
    if(it != variables.end())
    {
        string retVarAddr = it->second;
        asmInstr += "\tmovl %eax, " + retVarAddr + "\n";
    } else{
        cout << "problem : the variable doesn't exist..." << endl;
    }

    return asmInstr;
}

string AsmWriter::writeFunc(Commande functionCmd)
{
    string asmInstr = "\t.global " + functionCmd.elements[0] + "\n";
    asmInstr += "\t.type\t"+ functionCmd.elements[0] +", @function\n";
    asmInstr += functionCmd.elements[0] += ":\n";
    asmInstr += "\tpushq\t%rbp\n";
    asmInstr += "\tmovq\t%rsp, %rbp\n";
    unsigned long nbParam = functionCmd.elements.size()-2;
    for(int i = 0 ; i<nbParam ; i++)
    {
        long index = nbParam*(-4);
        string varAddress = to_string(index) + "(%rbp)";
        string varName = "!t" + to_string(nbParam);
        variables.insert(make_pair(varName, varAddress));
        asmInstr += "\tmovl\t" + paramRegister[i] + ", " + to_string(index) + "(%rbp)\n";
    }
    return asmInstr;
}

void AsmWriter::printVariableMap()
{
    map<string, string>::iterator it;
    for (it = variables.begin() ; it != variables.end() ; ++it)
    {
        cout << it->first << " @" << it->second << endl;
    }
}