//
// Created by halunka on 26/03/19.
//

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
        SIMPLE_BLOCK,
        PREC_IF_BLOCK_RIGHT,
        PREC_IF_BLOCK_LEFT,
        IF_BLOCK,
        ELSE_BLOCK
    };

class AsmWriter {
public:
    AsmWriter(string const nom, string const outName, string const arbre)
            : inFile(nom), outFile(outName), arbreAntlr(arbre) {flagCounter=0;}
    AsmWriter(){flagCounter=0;}
    void setNomFichierInput(string nomFichier);
    void setNomFichierOutput(string nomFichier);
    bool convert();
    bool writeOutputFile(matrice resultat);
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
    string writeIf(Commande multiplicationCmd);
    string generateIfLine(Commande curCommande);
    string writePredicat(Commande returnCmd, string nextFlag);
    void browseGraph(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter);
    void browseBlock(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter);
    string writeFuncCall(Commande functionCmd);
    string writeFuncAff(Commande functionCmd);



    string inFile;
    string outFile;
    string arbreAntlr;
    map<string, string> variables; // nom, adresse
    vector<string> namespaceFlags;
    int flagCounter;

};


#endif //PLD_COMP_ASMWRITER_H
