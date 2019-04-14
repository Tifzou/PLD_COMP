/*************************************************************************
                           PLD_COMP  -  description
    Classe en charge de la transformation en assembleur des blocks renvoyés par l'IR
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Interface de la classe <AsmWriter> (fichier AsmWriter.h) ----------------
#ifndef PLD_COMP_ASMWRITER_H
#define PLD_COMP_ASMWRITER_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility> // pair
#include <vector>
#include <stdio.h>
#include "Symbole.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


// enum qui definit les différents flags pour les structures au sein du programme à compiler
enum Flag
{
    IF_FLAG,
    ELSE_FLAG,
    WHILE_FLAG,

};

// enum qui definit les différents types de blocks pour les structures au sein du programme à compiler
enum typeBlock
{
    FIRST_BLOCK,
    SIMPLE_BLOCK,
    PREC_IF_BLOCK_RIGHT,
    PREC_IF_BLOCK_LEFT,
    IF_BLOCK,
    ELSE_BLOCK
};

//------------------------------------------------------------------------
// Rôle de la classe <AsmWriter>
// Transformer les blocks renvoyés par l'IR en assembleur x86
//------------------------------------------------------------------------

class AsmWriter {
//----------------------------------------------------------------- PUBLIC
public:

    //-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi :
    //      Le constructeur initialise les différents attibuts et structures nécessaires à la transformation
    // Contrat :
    //      Le système doit avoir les droits en écriture sur le répertoire d'exécution
    //      L'arbre doit être bien formé pour pouvoir être transformé correctement
    AsmWriter(string const outName, string const arbre)
            : outFile(outName), arbreAntlr(arbre)
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


    // Mode d'emploi :
    //      Surcharge du constructeur de base
    // Contrat :
    //      Ne pas utiliser ce dernier
    AsmWriter(){flagCounter=0;}

    // Mode d'emploi :
    //      Destructeur de base
    // Contrat :
    //      Aucun
    virtual ~AsmWriter(){}

//----------------------------------------------------- Méthodes publiques

    // Mode d'emploi :
    //      Permet de changer le nom du fichier a générer
    // Contrat :
    //      Utilisable dans le cas d'une ré-exécution du composant
    void setNomFichierOutput(string nomFichier);

    // Mode d'emploi :
    //      Permet de lancer la conversion en asm et l'écriture du fichier correspondant
    // Contrat :
    //      Aucun
    bool writeOutputFile(Cell *firstBlock, Cell *lastBlock);

    // Mode d'emploi :
    //      Permet d'afficher le mappage <variable,adresse> généré lors de la conversion
    // Contrat :
    //      Aucun
    void printVariableMap();

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
    // Mode d'emploi :
    //      Permet de convertir le return en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeReturn(Commande returnCmd);

    // Mode d'emploi :
    //      Permet de convertir l'affectation en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeAff(Commande affectationCmd);

    // Mode d'emploi :
    //      Permet de convertir la déclaration de variable en assembleur
    // Contrat :
    //      Aucun
    void writeDec(Commande declarationCmd);

    // Mode d'emploi :
    //      Permet de convertir la définition (affectation+déclaration) de variable en assembleur
    //      et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeDef(Commande definitionCmd);

    // Mode d'emploi :
    //      Permet de convertir l'opération arithmétique en assembleur
    //      et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeOperation(Commande operationCmd);

    // Mode d'emploi :
    //      Permet de convertir l'addition en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeAdd(Commande additionCmd);

    // Mode d'emploi :
    //      Permet de convertir la soustraction en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeSub(Commande substractionCmd);

    // Mode d'emploi :
    //      Permet de convertir la multiplication en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeMult(Commande multiplicationCmd);

    // Mode d'emploi :
    //      Permet de convertir le if en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeIf(int curFlagCounter);

    //TODO commenter les méthodes restantes quand le comportement sera définit
    // Mode d'emploi :
    //      Permet de convertir ???? du if en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string generateIfLine(Commande curCommande);

    // Mode d'emploi :
    //      Permet de convertir la condition du if en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writePredicat(Commande returnCmd, string nextFlag);
    void browseGraph(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter);
    void browseBlock(Cell *block, ofstream &myfile, typeBlock typeCurBlock, int curFlagCounter);
    string writeFunc(Commande functionCmd);

    // Mode d'emploi :
    //      Permet de convertir l'appel à la fonction correspondate en assembleur et renvoie le code correspondant
    // Contrat :
    //      Aucun
    string writeFuncCall(Commande functionCmd);
    string writeFuncAff(Commande functionCmd);


//----------------------------------------------------- Attributs protégés
    string outFile;
    string arbreAntlr;
    map<string, string> variables; // nom, adresse
    vector<string> namespaceFlags;
    vector<string> paramRegister; // nom de registre parametres
    int flagCounter;

//----------------------------------------------------------- Types privés
};


#endif //PLD_COMP_ASMWRITER_H
