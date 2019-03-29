/*************************************************************************
                           PLD_COMP  -  description
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Interface de la classe <Symbole> (fichier Symbole.h) ----------------
#if ! defined (SYMBOLE_H)
#define SYMBOLE_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum commandeType {ERR, WARN, VAR_DEC, VAR_DEF, OPER, RET, AFF};

typedef struct Commande
{
    commandeType type;
    vector<string> elements;
} Commande;

typedef vector<Commande> matrice;

//------------------------------------------------------------------------
// Rôle de la classe <Symbole>
//
//
//------------------------------------------------------------------------

class Symbole
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool varExist(string var);
    // Mode d'emploi :
    //
    // Contrat :
    //


    bool varDef(string var);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void writeStack(Commande curCommande)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        resp.push_back(curCommande);
    }


    void writeStack(commandeType code, vector<string> commande)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        Commande curCommande;
        curCommande.type=code;
        curCommande.elements = commande;
        resp.push_back(curCommande);
    }


    void pushInTemporalCommande(commandeType code, vector<string> commande)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.type = code;
        temporalStackCommande.elements = commande;
    }

    void pushInTemporalCommande(vector<string> commande)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.elements=commande;
    }

    void pushInTemporalCommande(commandeType code)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.type=code;
    }

    void pushInTemporalCommande(string element)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.elements.push_back(element);
    }

    void popBackLastElemTmpCommande()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.elements.pop_back();
    }

    void deleteTemporalCommand()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.type=ERR;
        temporalStackCommande.elements.clear();
    }


//----------------------------------------------------- Getter et Setter

    Commande getTemporalCommande()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return temporalStackCommande;
    }


    matrice* getStack()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return &resp;
    }


//-------------------------------------------- Constructeurs - destructeur
    Symbole(){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Symbole(){}
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    matrice resp;
    Commande temporalStackCommande;
    int SP;

//----------------------------------------------------------- Types privés

};

#endif // SYMBOLE_H
