/*************************************************************************
                           PLD_COMP  -  description
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

#ifndef PLD_COMP_ASMWRITER_H
#define PLD_COMP_ASMWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility> // pair
#include <vector>
#include <stdio.h>
#include "Symbole.h"

using namespace std;
enum Flag
    {
        IF_FLAG,
        ELSE_FLAG,
        WHILE_FLAG,

    };

enum typeBlock
    {
        FIRST_BLOCK,
        SIMPLE_BLOCK,
        PREC_IF_BLOCK_RIGHT,
        PREC_IF_BLOCK_LEFT,
        IF_BLOCK,
        ELSE_BLOCK
    };

class AsmWriter {
public:
    AsmWriter(string const nom, string const outName, string const arbre)
            : inFile(nom), outFile(outName), arbreAntlr(arbre)
    {
        flagCounter=0;
        // {RDI, RSI, RDX, RCX, R8, R9}
        paramRegister.push_back("%rdi");
        paramRegister.push_back("%rsi");
        paramRegister.push_back("%rdx");
        paramRegister.push_back("%rcx");
        paramRegister.push_back("%r8");
        paramRegister.push_back("%r9");
    }
    AsmWriter(){flagCounter=0;}
    void setNomFichierInput(string nomFichier);
    void setNomFichierOutput(string nomFichier);
    bool writeOutputFile(Cell *firstBlock);
    void printVariableMap();

protected:
    string writeReturn(Commande returnCmd);
    string writeAff(Commande affectationCmd);
    void writeDec(Commande declarationCmd);
    string writeDef(Commande definitionCmd);
    string writeOperation(Commande operationCmd);
    string writeAdd(Commande additionCmd);
    string writeSub(Commande substractionCmd);
    string writeMult(Commande multiplicationCmd);
    string writeIf(int curFlagCounter);
    string generateIfLine(Commande curCommande);
    string writePredicat(Commande returnCmd, string nextFlag);
    void browseGraph(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter);
    void browseBlock(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter);
    string writeFunc(Commande functionCmd);
    string writeFuncCall(Commande functionCmd);
    string writeFuncAff(Commande functionCmd);



    string inFile;
    string outFile;
    string arbreAntlr;
    map<string, string> variables; // nom, adresse
    vector<string> namespaceFlags;
    vector<string> paramRegister; // nom de registre parametres
    int flagCounter;

};


#endif //PLD_COMP_ASMWRITER_H
