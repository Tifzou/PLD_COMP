/*************************************************************************
                           PLD_COMP  -  description

    Classe réalisant l'IR et génèrant la représentation intermédiaire
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

// enum qui definit les différents types de commandes contenues dans la structure
// il n'est pas obligatoire d'adopter la même notation sur tout le projet
//mais peut être pratique pour la clareté
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
    FUNC_AFF,
    WHILE,
    CONDITIONWHILE,
    AFFL,
};

//structure contenant une commande correspondant à un type defini par 1 enum particuliere
//dont les elements de la commandes sont contenues dans un vecteur de string
typedef struct Commande
{
    commandeType type;
    vector<string> elements;
} Commande;

//la liste des commandes
typedef vector<Commande> matrice;

// block du control flow graph (cfg)
// contient la liste des commandes et des pointeurs vers les 2 blocks suivants
typedef struct Cell
{
    matrice data;
    Cell *suivant1;
    Cell *suivant2;
} Cell;

// représentation du CFG - accès au premier et dernier élement du CFG
typedef struct ListC
{
    Cell *first;
    Cell *last; //penser à garder les traces pour tous les ifs en stockant un vector des pointeurs
} ListC;

//------------------------------------------------------------------------
// Rôle de la classe <Symbole>
// génère la représentation intermédiaire
//------------------------------------------------------------------------

class Symbole
{
    //----------------------------------------------------------------- PUBLIC

  public:
    //----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //      vérifie qu'une variable a été déclarée
    //      renvoie true si oui, false sinon
    // Contrat :
    //      Aucun
    bool varExist(string var);

    // Mode d'emploi :
    //      vérifie qu'une variable a déjà une valeur soit avec une définition soit avec une affectation
    //      renvoie true si oui, false sinon
    // Contrat :
    //      renvoie false si la variable n'a pas été déclarée
    bool varDef(string var);

    // Mode d'emploi :
    //
    // Contrat :
    //
    bool functExist(string funct);

    // Mode d'emploi :
    //      ajoute une commande à la liste de commandes
    // Contrat :
    //      la commande doit être complète
    void writeStack(Commande curCommande);

    // TODO : à supprimer ? vu qu'elle n'est pas utilisée
    // Mode d'emploi :
    //      ajoute une commande à la liste de commandes
    // Contrat :
    //      la commande est créée dans cette méthode directement
    void writeStack(commandeType code, vector<string> commande);

    // Mode d'emploi :
    //      ajoute une liste de commandes à la liste de commandes existante
    // Contrat :
    //      les commandes doivent être complètes
    void writeStack(matrice commandes);


    // Mode d'emploi :
    //      crée une commande temporaire
    void pushInTemporalCommande(commandeType code, vector<string> commande)
    {
        temporalStackCommande.type = code;
        temporalStackCommande.elements = commande;
    }

    // TODO : à supprimer ? vu qu'elle n'est pas utilisée et n'a pas de code ?
    // Mode d'emploi :
    //      crée une commande temporaire
    // Contrat :
    //      ne possède pas de code définissant le type de la commande
    void pushInTemporalCommande(vector<string> commande)
    {
        temporalStackCommande.elements = commande;
    }

    // Mode d'emploi :
    //      crée une commande temporaire
    // Contrat :
    //      ne possède pas de corps définissant les instructions de la commande
    void pushInTemporalCommande(commandeType code)
    {
        temporalStackCommande.type = code;
    }

    // Mode d'emploi :
    // crée une commande temporaire
    // Contrat :
    //      ne possède pas de code définissant le type de la commande
    //      la commande ne possède qu'un seul élément dans le vector
    void pushInTemporalCommande(string element)
    {
        temporalStackCommande.elements.push_back(element);
    }

    void popBackLastElemTmpCommande()
    // Mode d'emploi :
    //      supprime le dernier élément ajouté à la commande
    {
        temporalStackCommande.elements.pop_back();
    }

    void deleteTemporalCommand()
    // Mode d'emploi :
    //      supprime le contenu de la commande temporaire
    // Contrat :
    //      le type de commande par défaut est ERR
    //      le corps de la commande est par défaut vide
    {
        temporalStackCommande.type = ERR;
        temporalStackCommande.elements.clear();
    }

    void pushTemporalMatriceVari(vector<string> element);
    // Mode d'emploi :
    //      crée une commande de type opération avec les elements
    //      l'ajoute à la liste de commandes temporaires (temporalExpression) // TODO changer le nom (?)

    // TODO : à supprimer ? vu qu'elle n'est pas utilisée
    void pushTemporalMatriceVari(commandeType code, vector<string> element);
    // Mode d'emploi :
    //      crée une commande
    //      l'ajoute à la liste de commandes temporaires (temporalExpression) // TODO changer le nom (?)

    int createTemporalVar()
    // Mode d'emploi :
    //      incrémente le nombre de variables temporaires
    // Contrat :
    //      le numéro d'une variable temporaire la définit
    {
        return tmpCounter++;
    }

    string retrieveVarType(string var);
    // Mode d'emploi :
    //      retourne le type de la variable
    // Contrat :
    //      parcourt le block actuel, la commande temporaire actuelle et les autres blocks
    //      ce qui induit qu'il n'est pas possible dans notre structure d'avoir plusieurs variables avec le même nom,
    //      même si l'une est dans une block if et l'autre non par exemple


    void createVar(string varName)
    // Mode d'emploi :
    //      ajoute la variable à la table des symboles
    {
        pair<string, int> p(varName, index++);
        tablesDesSymboles.insert(p);
    }

    void pushIntoFlowControl();
    // Mode d'emploi :
    //      crée un nouveau block dans le graph de controle
    //      l'ajoute au CFG
    // Contrat :
    //      la liste de commandes est remise à 0
    //      toutes les variables temporaires sont remises à 0


    void pushIfIntoFlowControl(Cell* curBlock);
    // Mode d'emploi :
    //      crée un nouveau block de type IF dans le graph de controle
    //      l'ajoute au CFG
    // Contrat :
    //      la liste de commandes est remise à 0
    //      toutes les variables temporaires sont remises à 0

    void pushElseIntoFlowControl(Cell* curBlock);
    // Mode d'emploi :
    //      crée un nouveau block de type ELSE dans le graph de controle
    //      l'ajoute au CFG
    // Contrat :
    //      la liste de commandes est remise à 0
    //      toutes les variables temporaires sont remises à 0

    void pushLastBlockIntoFlowControl();
    // Mode d'emploi :
    //      crée un nouveau block le graph de controle
    //      l'ajout au CFG en parcourant le graphe et en attachant le block courant à chaque block qui a un nullptr
    // Contrat :
    //      la liste de commandes est remise à 0
    //      toutes les variables temporaires sont remises à 0


    void deleteTemporalExpression()
    // Mode d'emploi :
    //      remet à 0 la liste des commandes temporaire
    {
        temporalExpression.clear();
    }

    void createFunction(string funcName)
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        pair<string, int> p(funcName, indexFunction++);
        tablesDesFonctions.insert(p);
    }


    bool browsBlocks(Cell *block, string var);
    // Mode d'emploi :
    //      parcourt le block et les blocks qui le suivent pour vérifier si la variable a été déclarée
    // Contrat :
    //      true si elle existe, false sinon

    bool browsBlocks(Cell *block, string &type, string var);
    // Mode d'emploi :
    //      parcourt le block et les blocks qui le suivent pour vérifier si la variable a été déclarée
    //      si elle existe, le type passé en paramètre est changé pour prendre la valeur de la variable trouvée
    // Contrat :
    //      true si elle existe, false sinon

    void browsBlocks(Cell *block, Cell *curBlock);
    // Mode d'emploi :
    //      parcourt le graphe et attache le block courant à chaque block qui a un nullptr

    bool browsBlocks(Cell *curCell);
    // Mode d'emploi :parcourt le block et les blocks qui le suivent pour detecter les erreurs presentes
    //si elles existe, la fonction affiche l'erreur
    //
    // Contrat :
    //true si aucuneerreur n'est detectée, false sinon.

    //----------------------------------------------------- Getter et Setter

    Commande getTemporalCommande()
    // Mode d'emploi :
    //      retourne la commande temporaire
    {
        return temporalStackCommande;
    }

    matrice *getStack()
    // Mode d'emploi :
    // return la liste des commandes du block actuel
    {
        return &resp;
    }

    ListC *getFlowControl()
    // Mode d'emploi :
    //      return la liste des blocks
    {
        return &*flowControl;
    }

    matrice *getTemporalExpression()
    // Mode d'emploi :
    //      return la liste de commande temporaire
    {
        return &temporalExpression;
    }

    //-------------------------------------------- Constructeurs - destructeur
    Symbole()
    // Mode d'emploi :
    //      initialise les variables
    {
        tmpCounter = 0;
        index = 0;
        indexFunction = 0;
        flowControl = new ListC();
    }

    virtual ~Symbole()
    {

    }

    // Mode d'emploi :
    //      libère la mémoire de tous les blocks du graphe de controle
    void destroyGraph(Cell* block);

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
