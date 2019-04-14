/*************************************************************************
                           PLD_COMP  -  description
    Classe en charge de la transformation en assembleur des blocks renvoyés par l'IR
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Réalisation de la classe <AsmWriter> (fichier AsmWriter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "AsmWriter.h"

#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include <stdio.h>


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void AsmWriter::setNomFichierOutput(string nom)
// Algorithme :
//
{
    outFile=nom;
}

//------------------------------------------------------------------------
void AsmWriter::browseBlock(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter)
// Algorithme :
//
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

           break;

        default:
            break;

    }
    for(itInstr = resultat.begin() ; itInstr != resultat.end() ; ++itInstr)
    {
        switch ((*itInstr).type) // {ERR, WARN, VAR_DEC, VAR_DEF, OPER, RET, AFF};
        {
            case 0 : // ERR
                break;
            case 1 : // WAR
                break;
            case 2 : // VAR DECLARATION
                writeDec((*itInstr));
                break;
            case 3 : // VAR DEFINITION
                myfile << writeDef((*itInstr));
                break;
            case 4 : // OPER
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
                myfile << writeReturn((*itInstr));
                break;
            case 6: // AFFECTATION
                myfile << writeAff((*itInstr));
                break;
            case 7: // IF
                myfile << writeIf(curFlagCounter);
                break;
            case 8: //Predicat (bloc)
                myfile << writePredicat(*itInstr, lastFlag);
                break;
            case 9: // FUNCTION
                myfile << writeFunc((*itInstr));
                break;
            case 10: //MAIN
                cerr << "in case MAIN" << endl;

#ifdef __APPLE__
                myfile << ".globl _main\n";
#else
                myfile << ".global main\n";
#endif
                myfile << "\t.type\t main, @function\n";
                myfile << "main:\n";
                myfile << "\tpushq\t%rbp"<<endl;
                myfile << "\tmovq\t%rsp, %rbp"<<endl;
                myfile << "\tsubq\t$16, %rsp" << endl; // TODO if more than 1 fct, change $16
                break;
            case 11: // FUNC_CALL
                myfile << writeFuncCall((*itInstr));
                break;
            case 12: // FUNC_AFF
                myfile << writeFuncAff((*itInstr));
                break;
            default:
                break;
        }
    }
}

//------------------------------------------------------------------------
void AsmWriter::browseGraph(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter)
// Algorithme :
//
{
    //curFlagCounter = flagCounter;

    if(block==nullptr || block->data.size()==0)
    {
        return;
    }

    browseBlock(block, myfile, typeCurBlock, curFlagCounter);



    if(typeCurBlock==PREC_IF_BLOCK_LEFT || typeCurBlock==PREC_IF_BLOCK_RIGHT)
    {
        curFlagCounter =flagCounter;
        flagCounter++;
        if(block->suivant1!= nullptr && block->suivant1->data.back().type==commandeType::CONDITION)
        {
            browseGraph(block->suivant1, myfile, PREC_IF_BLOCK_LEFT, flagCounter);
            myfile << "\tjmp endif" + to_string(curFlagCounter) + "\n";
        }
        else
        {
            browseBlock(block->suivant1, myfile, IF_BLOCK, curFlagCounter+1);
            myfile << "\tjmp endif" + to_string(curFlagCounter) + "\n";

        }

        if(block->suivant2!= nullptr && block->suivant2->data.size()!=0 && block->suivant2->data.back().type==commandeType::CONDITION )
        {
            myfile << "else" + to_string(curFlagCounter) + ":\n";
            browseGraph(block->suivant2, myfile, PREC_IF_BLOCK_RIGHT, flagCounter);
            myfile << "endif" + to_string(curFlagCounter) + ":\n";
        }
        else
        {
            if(block->suivant2!= nullptr && !block->suivant2->data.empty())
            {
                myfile << "else" + to_string(curFlagCounter) + ":\n";
            }
            browseBlock(block->suivant2, myfile, ELSE_BLOCK, curFlagCounter);
            myfile<<"endif"+to_string(curFlagCounter)+":\n";
        }


    }
    else
    {
        browseGraph(block->suivant1, myfile, SIMPLE_BLOCK, flagCounter);
    }

}


bool AsmWriter::writeOutputFile(Cell *firstBlock, Cell *lastBlock) {
    ofstream myfile (outFile);
    if (myfile.is_open()){
        myfile << ".text\n";
        if(firstBlock->data.back().type==commandeType::CONDITION)
        {
            browseGraph(firstBlock, myfile, PREC_IF_BLOCK_LEFT, flagCounter);
            browseBlock(lastBlock, myfile, SIMPLE_BLOCK, 0);
        }
        else
        {
            browseGraph(firstBlock, myfile, FIRST_BLOCK, 0);
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

//------------------------------------------------------------------------
string AsmWriter::writeReturn(Commande returnCmd)
// Algorithme :
//
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

//------------------------------------------------------------------------
string AsmWriter::writeAff(Commande affectationCmd)
// Algorithme :
//
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

//------------------------------------------------------------------------
void AsmWriter::writeDec(Commande declarationCmd)
// Algorithme :
//
{
    string varName = declarationCmd.elements[1];
    int stackPos = (variables.size()+1) * (-4);
    string varAddress = to_string(stackPos) + "(%rbp)";
    variables.insert(make_pair(varName, varAddress));
}

//------------------------------------------------------------------------
string AsmWriter::writeDef(Commande definitionCmd)
// Algorithme :
//
{
    writeDec(definitionCmd);
    string asmInstr = writeAff(definitionCmd);
    return asmInstr;
}

//------------------------------------------------------------------------
string AsmWriter::writeOperation(Commande operationCmd)
// Algorithme :
//
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

//------------------------------------------------------------------------
string AsmWriter::writeAdd(Commande additionCmd)
// Algorithme :
//
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

//------------------------------------------------------------------------
string AsmWriter::writeSub(Commande substractionCmd)
// Algorithme :
//
{
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

//------------------------------------------------------------------------
string AsmWriter::writeMult(Commande multiplicationCmd)
// Algorithme :
//
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

//------------------------------------------------------------------------
string AsmWriter::writeIf(int curFlagCounter)
// Algorithme :
//
{
    string flagIf = "if"+std::to_string(curFlagCounter);
    namespaceFlags.push_back(flagIf);
    flagIf+=":\n";
    return flagIf;

}

//------------------------------------------------------------------------
void AsmWriter::printVariableMap()
// Algorithme :
//
{
    map<string, string>::iterator it;
    for (it = variables.begin() ; it != variables.end() ; ++it)
    {
        cout << it->first << " @" << it->second << endl;
    }
}

//------------------------------------------------------------------------
string AsmWriter::generateIfLine(Commande curCommande)
// Algorithme :
//
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

//------------------------------------------------------------------------
string AsmWriter::writePredicat(Commande ifCondition, string nextFlag)
// Algorithme :
//
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

//------------------------------------------------------------------------
string AsmWriter::writeFunc(Commande functionCmd)
// Algorithme :
//
{
    string functName = functionCmd.elements[0];
    string asmInstr = "\t.global " + functName + "\n";
    asmInstr += "\t.type\t"+ functName + ", @function\n";
    asmInstr += functName + ":\n";
    asmInstr += "\tpushq\t%rbp\n";
    asmInstr += "\tmovq\t%rsp, %rbp\n";

    //cout << functionCmd.elements[0] << functionCmd.elements[1] << functionCmd.elements[2] << endl;
    if(functionCmd.elements.size() >1)
    {
        cout << "elements contains at least 1 param" << endl;
        unsigned long nbParam = (functionCmd.elements.size())-1;
        cout << nbParam << endl;
        for(unsigned long i = 1 ; i<=nbParam ; i++)
        {
            cout << "n° param " << i-1 << endl;
            long index = i*(-4);
            string varAddress = to_string(index) + "(%rbp)";
            cout << varAddress << endl;
            string varName = functionCmd.elements[i];
            cout << varName << endl;
            pair<string, string> p(varName, varAddress);
            //variables.insert(make_pair(varName, varAddress));
            variables.insert(p);
            asmInstr += "\tmovl\t" + paramRegister[i-1] + ", " + varAddress + "\n";
        }
    }
    return asmInstr;
}

//------------------------------------------------------------------------
string AsmWriter::writeFuncCall(Commande functionCmd)
// Algorithme :
//
{
    string funcName = functionCmd.elements[0];
    string asmInstr = "";
    for (int i = 1; i < functionCmd.elements.size() ; i++)
    {
        string varName = functionCmd.elements[i];
        map<string, string>::iterator it = variables.find(varName);
        if (it != variables.end())
        {
            string varAddr = it->second;
            asmInstr += "\tmovl\t" + varAddr + ", " + paramRegister[i-1] + "\n";
        }
    }
    asmInstr += "\tcall " + funcName + "\n";
    return asmInstr;
}

//------------------------------------------------------------------------
string AsmWriter::writeFuncAff(Commande functionCmd)
// Algorithme :
//
{
    string funcName = functionCmd.elements[0];
    string asmInstr = "";
    // parameters
    for (int i = 2; i < functionCmd.elements.size() ; i++)
    {
        string varName = functionCmd.elements[i];
        cout << varName << endl;
        map<string, string>::iterator it = variables.find(varName);
        if (it != variables.end())
        {
            string varAddr = it->second;
            asmInstr += "\tmovl\t" + varAddr + ", " + paramRegister[i-1] + "\n";
        }
    }
    asmInstr += "\tcall " + funcName + "\n";

    // return value
    map<string, string>::iterator it = variables.find(functionCmd.elements[1]);
    if(it != variables.end())
    {
        string retVarAddr = it->second;
        asmInstr += "\tmovl\t%eax, " + retVarAddr + "\n";
    }

    return asmInstr;
}