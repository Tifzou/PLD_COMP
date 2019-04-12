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

class AsmWriter {
public:
    AsmWriter(string const nom, string const outName, string const arbre)
            : inFile(nom), outFile(outName), arbreAntlr(arbre)
    {// {RDI, RSI, RDX, RCX, R8, R9}
        paramRegister.push_back("%rdi");
        paramRegister.push_back("%rsi");
        paramRegister.push_back("%rdx");
        paramRegister.push_back("%rcx");
        paramRegister.push_back("%r8");
        paramRegister.push_back("%r9");
    }
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
    string writeFuncCall(Commande functionCmd);
    string writeFuncAff(Commande functionCmd);
    string writeFunc(Commande functionCmd);


    string inFile;
    string outFile;
    string arbreAntlr;
    map<string, string> variables; // nom, adresse
    vector<string> paramRegister; // nom fonction, vector<nom de registre parametres>

};


#endif //PLD_COMP_ASMWRITER_H
