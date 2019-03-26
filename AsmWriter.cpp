//
// Created by halunka on 26/03/19.
//

#include "AsmWriter.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

void AsmWriter::setNomFichier(string nom){
    nomFichier=nom;
};

bool AsmWriter::convert(){
    size_t foundCpp=nomFichier.find(".cpp",0);
    if (foundCpp!=std::string::npos){
        nomFichier.replace(nomFichier.end()-4,nomFichier.end(),".asm");
        cout<<"Okay, .cpp rules"<<endl;
    }else{
        size_t foundC=nomFichier.find(".c",0);
        if (foundC!=std::string::npos){
            cout<<"Okay, .c rules"<<endl;
            nomFichier.replace(nomFichier.end()-2,nomFichier.end(),".s");
        }else{
            cerr<<"Le fichier d'entrée n'a pas la bonne extension !\n";
            return 0;
        }
    }
    return 1;
};