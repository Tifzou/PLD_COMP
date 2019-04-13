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
    }else{
        size_t foundC=inFile.find(".c",0);
        if (foundC!=std::string::npos){
            inFile.replace(inFile.end()-2,inFile.end(),".s");
        }else{
            cerr<<"Le fichier d'entrée n'a pas la bonne extension !\n";
            return 0;
        }
    }
    return 1;
}

void AsmWriter::browseBlock(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter)
{
    vector<Commande> resultat= block->data;
    vector<Commande>::iterator itInstr;
    string lastFlag;

    //On gère le type de flag en fonction du type de block (pour block while c'est ici qu'on fera un jump en boucle)
    switch(typeCurBlock)
    {
        case IF_BLOCK:

            break;

        case ELSE_BLOCK:
        {
            if(!block->data.empty())
            {
                myfile << "else" + to_string(curFlagCounter) + ":\n";
            }

            break;
        }

        case PREC_IF_BLOCK_LEFT:
            if(block->suivant2->data.size()==0)
            {
                lastFlag="endif"+to_string(curFlagCounter);
            }
            else
            {
                lastFlag="else"+to_string(curFlagCounter);
            }

            break;

        case PREC_IF_BLOCK_RIGHT:
        {

            myfile << "else" + to_string(curFlagCounter) + ":\n";;

            if(block->suivant2->data.size()==0)
            {
                lastFlag="endif"+to_string(curFlagCounter);
            }
            else
            {
                lastFlag="else"+to_string(curFlagCounter);
            }

            break;
        }

        case SIMPLE_BLOCK: //à changer pour if multiples

            myfile<<"endif"+to_string(curFlagCounter)+":\n";
            break;

        default:
            break;

    }
    for(itInstr = resultat.begin() ; itInstr != resultat.end() ; ++itInstr)
    {
        switch ((*itInstr).type) // {ERR, WARN, VAR_DEC, VAR_DEF, OPER, RET, AFF};
        {
            case 0 : // ERR
                //cerr << "in case ERR" << endl;
                break;
            case 1 : // WAR
                //cerr << "in case WAR" << endl;
                break;
            case 2 : // VAR DECLARATION
                //cerr << "in case VAR_DEC" << endl;
                writeDec((*itInstr));
                break;
            case 3 : // VAR DEFINITION
                //cerr << "in case VAR_DEF" << endl;
                myfile << writeDef((*itInstr));
                break;
            case 4 : // OPER
                //cerr << "in case OPER" << endl;
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
                //cerr << "in case RET" << endl;
                myfile << writeReturn((*itInstr));
                break;
            case 6: // AFFECTATION
                //cerr << "in case AFF" << endl;
                myfile << writeAff((*itInstr));
                break;
            case 7: // IF
                //cerr << "in case IF" << endl;
                myfile << writeIf(curFlagCounter);
                break;
            case 8: //Predicat (bloc)
                //cerr << "in case Predicat" << endl;
                myfile << writePredicat(*itInstr, lastFlag);
                break;
            case 9: // FUNCTION
                cerr << "in case FUNCTION" << endl;
                writeFunc((*itInstr));
                break;
            case 10: //MAIN
                cerr << "in case MAIN" << endl;
                myfile << ".global main\n";
                myfile << "\t.type\t main, @function\n";
                myfile << "main:\n";
                myfile << "\tpushq\t%rbp"<<endl;
                myfile << "\tmovq\t%rsp, %rbp"<<endl;
                myfile << "\tsubq\t$16, %rsp" << endl; // TODO if more than 1 fct, change $16
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
    //changer pour plusieurs if
    /*if(typeCurBlock==IF_BLOCK || typeCurBlock==PREC_IF_BLOCK_LEFT)
    {
        myfile << "\tjmp endif" + to_string(flagCounter) + "\n";
    }*/
}

void AsmWriter::browseGraph(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int flagCounter)
{
    int curFlagCounter = flagCounter;

    if(block==nullptr || block->data.size()==0)
    {
        return;
    }

    browseBlock(block, myfile, typeCurBlock, flagCounter);



    if(typeCurBlock==PREC_IF_BLOCK_LEFT || typeCurBlock==PREC_IF_BLOCK_RIGHT)
    {
        cout<<"blockIF"+to_string(curFlagCounter);
        flagCounter++;
        if(block->suivant1!= nullptr && block->suivant1->data.back().type==commandeType::CONDITION)
        {
            browseGraph(block->suivant1, myfile, PREC_IF_BLOCK_LEFT, curFlagCounter+1);
            myfile << "\tjmp endif" + to_string(curFlagCounter) + "\n";
        }
        else
        {
            browseBlock(block->suivant1, myfile, IF_BLOCK, curFlagCounter+1);
            myfile << "\tjmp endif" + to_string(curFlagCounter) + "\n";

        }

        if(block->suivant2!= nullptr && block->suivant2->data.size()!=0 && block->suivant2->data.back().type==commandeType::CONDITION )
        {
            browseGraph(block->suivant2, myfile, PREC_IF_BLOCK_RIGHT, curFlagCounter);
            myfile << "\tjmp endif" + to_string(curFlagCounter) + "\n";
        }
        else
        {
            browseGraph(block->suivant2, myfile, ELSE_BLOCK, curFlagCounter);
        }


    }
    else
    {
        browseGraph(block->suivant1, myfile, SIMPLE_BLOCK, flagCounter);
    }


}


bool AsmWriter::writeOutputFile(Cell *firstBlock) {
    ofstream myfile (outFile);
    if (myfile.is_open()){
        myfile << ".text\n";
        int stackPtr = 0;
        //for loop was here

        if(firstBlock->data.back().type==commandeType::CONDITION)
        {
            browseGraph(firstBlock, myfile, PREC_IF_BLOCK_LEFT, flagCounter);
        }
        else
        {
            browseGraph(firstBlock, myfile, FIRST_BLOCK, flagCounter);
        }

        myfile << "\tmovq\t%rbp, %rsp" << endl;
        myfile << "\tpopq\t%rbp"<<endl;
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


string AsmWriter::writeIf(int curFlagCounter)
{
    string flagIf = "if"+std::to_string(curFlagCounter);
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

string AsmWriter::generateIfLine(Commande curCommande)
{
    map<string, string>::iterator it;
    string addVar1;
    string addVar2;
    it = variables.find(curCommande.elements[2]);
    if(it!=variables.end())
    {
        addVar1 = it->second;
    }
    else
    {
        addVar1 = curCommande.elements[2];
    }


    it = variables.find(curCommande.elements[4]);
    if(it!=variables.end())
    {
        addVar2 = it->second;
    }
    else
    {
        addVar2 = curCommande.elements[2];
    }

    string asmInstr = "\tmovl\t"+addVar1+", %edx\n";
    asmInstr += "\tmovl\t"+addVar2+", %eax\n";
    asmInstr += "\tcmpl\t%edx, %eax\n";

    return asmInstr;
}

string AsmWriter::writePredicat(Commande ifCondition, string nextFlag)
{
    string line = generateIfLine(ifCondition);
    if (ifCondition.elements[3] == "==")
    {
        line+="\tjne "+ nextFlag+"\n";
    }
    else if (ifCondition.elements[3] == ">=")
    {
        line+="\tjb "+ nextFlag+"\n";
    }
    else if (ifCondition.elements[3] == ">")
    {
        line+="\tjbe "+ nextFlag+"\n";

    }
    else if (ifCondition.elements[3] == "<=")
    {
        line+="\tja "+ nextFlag+"\n";
    }
    else if (ifCondition.elements[3] == "<")
    {
        line+="\tjae "+ nextFlag+"\n";

    }
    else if (ifCondition.elements[3] == "!=")
    {
        line+="\tje "+ nextFlag+"\n";
    }

    return line;
}

string AsmWriter::writeFunc(Commande functionCmd)
{
    string functName = functionCmd.elements[0];
    string asmInstr = "\t.global " + functName + "\n";
    asmInstr += "\t.type\t"+ functName + ", @function\n";
    asmInstr += functName + ":\n";
    asmInstr += "\tpushq\t%rbp\n";
    asmInstr += "\tmovq\t%rsp, %rbp\n";

    cout << functionCmd.elements[0] << functionCmd.elements[1] << functionCmd.elements[2] << endl;
    if(functionCmd.elements.size() >1)
    {
        cout << "elements contains at least 1 param" << endl;
        unsigned long nbParam = (functionCmd.elements.size())-2;
        cout << nbParam << endl;
        for(unsigned long i = 0 ; i<nbParam ; i++)
        {
            cout << i << endl;
            long index = nbParam*(-4);
            string varAddress = to_string(index) + "(%rbp)";
            cout << varAddress << endl;
            string varName = "!t" + to_string(nbParam);
            cout << varName << endl;
            pair<string, string> p(varName, varAddress);
            cout << "une paire a ete creee" << endl;
            //variables.insert(make_pair(varName, varAddress));
            variables.insert(p);
            cout << "la paire a ete inseree dans la map" << endl;
            //asmInstr += "\tmovl\t" + paramRegister[i] + ", " + varAddress + "(%rbp)\n";
        }
    }
    return asmInstr;
}

string AsmWriter::writeFuncCall(Commande functionCmd)
{
    string funcName = functionCmd.elements[0];
    string asmInstr = "\tcall " + funcName + "\n";
    return asmInstr;
}

string AsmWriter::writeFuncAff(Commande functionCmd)
{
    string funcName = functionCmd.elements[0];
    string asmInstr = "\tcall " + funcName + "\n";
    map<string, string>::iterator it = variables.find(functionCmd.elements[1]);
    if(it != variables.end())
    {
        string retVarAddr = it->second;
        asmInstr += "\tmovl %eax, " + retVarAddr + "\n";
    }

    return asmInstr;
}