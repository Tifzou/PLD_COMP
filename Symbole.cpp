/*************************************************************************
                           PLD_COMP  -  description
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Réalisation de la classe <Symbole> (fichier Symbole.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Symbole.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------------------------------
bool Symbole::varExist(string var)
// Algorithme : renvoi 'true' si la variable 'var' est déjà déclarée
//
{
    for(Commande commande : resp)
    {
        if((commande.type == commandeType::VAR_DEC || commande.type == commandeType::VAR_DEF) && commande.elements[1] == var)
        {
            return true;
        }
    }
    return false;
}


//------------------------------------------------------------------------
bool Symbole::varDef(string var)
// Algorithme : renvoi 'true si la variable 'var' possède une valeur à l'issue d'une declaration avec affectation ou juste une affectation
//
{
    for(Commande commande : resp)
    {
        if((commande.type == commandeType::VAR_DEF || commande.type == commandeType::AFF)  && commande.elements[1] == var)
        {
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------
bool Symbole::functExist(string funct)
// Algorithme : renvoi 'true' si la variable 'var' est déjà déclarée
//
{
    /*for(Commande commande : resp)
    {
        if((commande.type == commandeType::FUNC) && commande.elements[1] == funct)
        {
            return true;
        }
    }
    return false;*/
    map<string, int>::iterator it = tablesDesFonctions.find(funct);
    if(it == tablesDesFonctions.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}


//------------------------------------------------------------------------
bool Symbole::browsBlocks(Cell *block, string &type, string var)
// Algorithme : renvoi 'true' si la variable 'var' est déjà déclarée en affectant à type le type de la variable
//
{
    if(block==nullptr)
    {
        return false;
    }

    for(Commande curCom: block->data)
    {
        if (curCom.elements[1] == var)
        {
            type = curCom.elements[0];
            return true;
        }
    }

    bool test = browsBlocks(block->suivant1, type, var) || browsBlocks(block->suivant2, type, var);
    return test;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
