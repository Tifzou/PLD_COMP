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

using namespace std;

class AsmWriter {
    public:
        AsmWriter(string const nom, string const outName, string const arbre)
            : inFile(nom), outFile(outName), arbreAntlr(arbre) {}
        void setNomFichierInput(string nomFichier);
        void setNomFichierOutput(string nomFichier);
        bool convert();
        bool writeOutputFile(vector<vector<string>> resultat);

    protected:
        string inFile;
        string outFile;
        string arbreAntlr;
        map<string, pair<string,int>> variables; // nom, <adresse, val>

};


#endif //PLD_COMP_ASMWRITER_H
