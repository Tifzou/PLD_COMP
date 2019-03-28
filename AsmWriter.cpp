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
}

bool AsmWriter::writeOutputFile() {
    ofstream myfile (outFile);
    if (myfile.is_open()){
        myfile << ".text\n";
        myfile << ".global main\n";
        myfile << "main:\n";
        myfile << "\tpushq\t%rbp"<<endl;
        myfile << "\tmovq\t%rsp, %rbp"<<endl;
        int stackPtr = 0;
        vector<vector<string>>::iterator itInstr;
        for(itInstr = resultat.begin() ; itInstr != resultat.end() ; ++itInstr)
        {
            vector<string>::iterator itString;
            itString = itInstr->begin(); // int

            string nomVar = itString[1];

            stackPtr -= 4;
            string adresseI = to_string(stackPtr)+"(%rbp)";

            int val;
            try
            {
                val = stoi(itString[2]);
            }
            catch (const invalid_argument& ia)
            {
                val = variables.find(itString[2])->second.second;
            }
            //cout << "val= " << val << endl;
            pair<string, int> descrVar (adresseI, val);
            variables.insert(pair<string, pair<string, int>>(nomVar, descrVar));

            myfile << "\tmovl\t$"<< val << ", " << stackPtr << "(%rbp)"<<endl;
            myfile << "\tmovl\t"<< stackPtr << "(%rbp), %eax"<<endl;
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