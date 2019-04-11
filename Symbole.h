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
    CONDITION,
    FUNC,
    MAIN,
    FUNC_CALL,
    FUNC_AFF
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
    Cell *last;
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

    bool functExist(string funct);
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
        curCommande.type = code;
        curCommande.elements = commande;
        resp.push_back(curCommande);
    }

    void writeStack(matrice commandes)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        for(Commande curCommande: commandes)
        {
            resp.push_back(curCommande);
        }
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

    void pushTemporalMatriceVari(vector<string> element)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        Commande line;
        line.type = OPER;
        line.elements = element;
        temporalExpression.push_back(line);
    }

    void pushTemporalMatriceVari(commandeType code, vector<string> element)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        Commande line;
        line.type = code;
        line.elements = element;
        temporalExpression.push_back(line);
    }


    int createTemporalVar()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        return tmpCounter++;
    }


    string retrieveVarType(string var)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        for (Commande vs : resp)
        {
            if (vs.elements[1] == var)
            {
                return vs.elements[0];
            }
        }

        for (Commande vs : temporalExpression)
        {
            if ((vs.type == commandeType::OPER)  && vs.elements[1] == var)
            {
                return vs.elements[0];
            }
        }

        return nullptr;
    }

    void createVar(string varName)
    {
        pair<string, int> p(varName, index++);
        tablesDesSymboles.insert(p);
    }

    void pushIntoFlowControl()
    {
        cout << "OK" << endl;
        if (flowControl->first == nullptr )
        {
            Cell *bloc = new Cell();
            flowControl->first = bloc;
            flowControl->last = flowControl->first;
        }
        else
        {

            Cell *bloc = new Cell();
            bloc->data = resp;
            flowControl->last->suivant1 = bloc;
            flowControl->last = flowControl->last->suivant1;
        }

        resp.clear();
    }

    void pushIfIntoFlowControl(int index)
    {
        Cell *bloc = new Cell();
        bloc->data = resp;

        switch (index)
        {
            case 1:
                if (flowControl->last->suivant1 == nullptr)
                {
                    flowControl->last->suivant1 = bloc;
                }
                else
                {
                    flowControl->last->suivant2 = bloc;
                }
                break;
            case 2:
                flowControl->last->suivant1->suivant1 = bloc;
                flowControl->last->suivant2->suivant1 = bloc;
                flowControl->last = flowControl->last->suivant1->suivant1;
                break;
        }
        resp.clear();
    }

    void deleteTemporalExpression()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        temporalExpression.clear();
    }

    void createFunction(string funcName)
    {
        pair<string, int> p(funcName, indexFunction++);
        tablesDesFonctions.insert(p);
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
        indexFunction = 0;
        flowControl = new ListC();
    }
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Symbole() {}
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
    map<string, int> tablesDesFonctions;
    int tmpCounter;
    int index;
    int indexFunction;

//----------------------------------------------------------- Types privés

};

#endif // SYMBOLE_H
