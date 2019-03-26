//
// Created by halunka on 26/03/19.
//

#ifndef PLD_COMP_ASMWRITER_H
#define PLD_COMP_ASMWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

class AsmWriter {
    public:
        AsmWriter(string const nom, string const arbre) : nomFichier(nom), arbreAntlr(arbre) {}
        void setNomFichier(string nomFichier);
        bool convert();

    protected:
        string nomFichier;
        string arbreAntlr;
};


#endif //PLD_COMP_ASMWRITER_H
