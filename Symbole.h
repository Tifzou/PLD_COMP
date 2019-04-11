/*************************************************************************
                           PLD_COMP  -  description
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Interface de la classe <Symbole> (fichier Symbole.h) ----------------
#if !defined(SYMBOLE_H)
#define SYMBOLE_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <vector>
#include <map>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//enume qui definit les différents type de commandes contenue dans la structure
// il n'est pas obligatoire d'adopter la même notation sur tout le projet
//mais peut être pratique pour la claireté
enum commandeType
{
    ERR,
    WARN,
    VAR_DEC,
    VAR_DEF,
    OPER,
    RET,
    AFF,
    IF,
    WHILE,
    CONDITION,
    CONDITIONWHILE
};

//structure contenant une commande correspondant à un type definit par 1 enum particulier
//dont les elements de la commandes sont contenues dans un vecteur de string
typedef struct Commande
{
    commandeType type;
    vector<string> elements;
} Commande;

//la liste des commandes
typedef vector<Commande> matrice;

typedef struct Cell
{
    matrice data;
    Cell *suivant1;
    Cell *suivant2;
} Cell;

typedef struct ListC
{
    Cell *first;
    Cell *last; //penser à garder les traces pour tous les ifs en stockant un vector des pointeurs
} ListC;

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

    void writeStack(Commande curCommande);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void writeStack(commandeType code, vector<string> commande);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void writeStack(matrice commandes);
    // Mode d'emploi :
    //
    // Contrat :
    //


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
        temporalStackCommande.elements = commande;
    }

    void pushInTemporalCommande(commandeType code)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalStackCommande.type = code;
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
        temporalStackCommande.type = ERR;
        temporalStackCommande.elements.clear();
    }

    void pushTemporalMatriceVari(vector<string> element);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void pushTemporalMatriceVari(commandeType code, vector<string> element);
    // Mode d'emploi :
    //
    // Contrat :
    //


    int createTemporalVar()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return tmpCounter++;
    }

    string retrieveVarType(string var);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void createVar(string varName)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        pair<string, int> p(varName, index++);
        tablesDesSymboles.insert(p);
    }

    void pushIntoFlowControl();
    // Mode d'emploi :
    //
    // Contrat :
    //


    void pushIfIntoFlowControl(int index);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void deleteTemporalExpression()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalExpression.clear();
    }


    bool browsBlocks(Cell *block, string var);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool browsBlocks(Cell *block, string &type, string var);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void browsBlocks(Cell *block, Cell *curBlock);
    // Mode d'emploi :
    //
    // Contrat :
    //


    //----------------------------------------------------- Getter et Setter

    Commande getTemporalCommande()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return temporalStackCommande;
    }

    matrice *getStack()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return &resp;
    }

    ListC *getFlowControl()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return &*flowControl;
    }

    matrice *getTemporalExpression()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return &temporalExpression;
    }

    //-------------------------------------------- Constructeurs - destructeur
    Symbole()
    {
        tmpCounter = 0;
        index = 0;
        flowControl = new ListC();
    }
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Symbole()
    {
        /*Cell *ptrBloc=flowControl->first;
        while (ptrBloc->)
        {
        }*/
    }
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
    matrice temporalExpression;
    ListC *flowControl;
    Commande temporalStackCommande;
    map<string, int> tablesDesSymboles;
    int tmpCounter;
    int index;

    //----------------------------------------------------------- Types privés
};

#endif // SYMBOLE_H
