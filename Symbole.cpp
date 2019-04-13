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
    if(tablesDesSymboles.find(var)!=tablesDesSymboles.end())
    {
        return true;
    }

    return false;
}


//------------------------------------------------------------------------
void Symbole::writeStack(Commande curCommande)
// Algorithme :
//
{
    resp.push_back(curCommande);
}


//------------------------------------------------------------------------
void Symbole::writeStack(commandeType code, vector<string> commande)
// Algorithme :
//
{
    Commande curCommande;
    curCommande.type = code;
    curCommande.elements = commande;
    resp.push_back(curCommande);
}


//------------------------------------------------------------------------
void Symbole::writeStack(matrice commandes)
// Algorithme :
//
{
    for (Commande curCommande : commandes)
    {
        resp.push_back(curCommande);
    }
}

//------------------------------------------------------------------------
void Symbole::pushTemporalMatriceVari(vector<string> element)
// Algorithme :
//
{
    Commande line;
    line.type = OPER;
    line.elements = element;
    temporalExpression.push_back(line);
}


//------------------------------------------------------------------------
void Symbole::pushTemporalMatriceVari(commandeType code, vector<string> element)
// Algorithme :
//
{
    Commande line;
    line.type = code;
    line.elements = element;
    temporalExpression.push_back(line);
}


//------------------------------------------------------------------------
string Symbole::retrieveVarType(string var)
// Algorithme :
//
{
    for (Commande vs : resp)
    {
        if (vs.elements.size()!=0 && vs.elements[1] == var)
        {
            return vs.elements[0];
        }
    }

    for (Commande vs : temporalExpression)
    {
        if ((vs.type == commandeType::OPER) && vs.elements[1] == var)
        {
            return vs.elements[0];
        }
    }

    string typeVar;

    if(browsBlocks(flowControl->first, typeVar, var))
    {
        return typeVar;
    }

    return nullptr;
}


//------------------------------------------------------------------------
void Symbole::pushIntoFlowControl()
// Algorithme :
//
{
    if (flowControl->first == nullptr )
    {
        Cell *bloc = new Cell();
        bloc->data = resp;
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
    temporalExpression.clear();
    temporalStackCommande.elements.clear();
    temporalStackCommande.type=ERR;

}


//------------------------------------------------------------------------
void Symbole::pushIfIntoFlowControl(Cell *curBlock)
// Algorithme :
//
{
    Cell *bloc = new Cell();
    bloc->data = resp;
    if(curBlock->suivant1==nullptr)
    {
        curBlock->suivant1 = bloc;
    }
    flowControl->last=bloc;

    resp.clear();
    temporalExpression.clear();
    temporalStackCommande.elements.clear();
    temporalStackCommande.type=ERR;
}

void Symbole::pushElseIntoFlowControl(Cell* curBlock)
{
    Cell *bloc = new Cell();
    bloc->data = resp;

    if(curBlock->suivant2==nullptr)
    {
        curBlock->suivant2 = bloc;
    }
    flowControl->last=bloc;
    resp.clear();
    temporalExpression.clear();
    temporalStackCommande.elements.clear();
    temporalStackCommande.type=ERR;
}


void Symbole::pushLastBlockIntoFlowControl()
{
    Cell *bloc = new Cell();
    bloc->data = resp;
    browsBlocks(flowControl->first, bloc);
    flowControl->last = flowControl->last->suivant1;
    resp.clear();
    temporalExpression.clear();
    temporalStackCommande.elements.clear();
    temporalStackCommande.type=ERR;
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
bool Symbole::browsBlocks(Cell *block, string var)
// Algorithme : renvoi 'true' si la variable 'var' est déjà déclarée
//
{
    if(block==nullptr)
    {
        return false;
    }

    for(Commande curCom: block->data)
    {
        if(curCom.elements[1]==var)
        {
            return true;
        }
    }
    bool test = browsBlocks(block->suivant1, var) || browsBlocks(block->suivant2, var);
    cout<<test<<endl;
    return test;
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


//------------------------------------------------------------------------
void Symbole::browsBlocks(Cell *block, Cell *curBlock)
// Algorithme : parcourt le graphe et attache le block courant à chaque block qui a un nullptr
//
{

    if(block==curBlock)
    {
        return;
    }
    Cell *tmpCell = new Cell();
    tmpCell->suivant1=curBlock;
    tmpCell->suivant2=curBlock;
    if(block->suivant1==nullptr)
    {
        block->suivant1=curBlock;
        block->suivant2=curBlock;
    }
    else
    {
        if(block->suivant2==nullptr)
        {
            block->suivant2=tmpCell;
        }
    }
    browsBlocks(block->suivant1, curBlock);
    browsBlocks(block->suivant2, curBlock);
}

//------------------------------------------------------------------------
bool Symbole::varDef(string var)
// Algorithme : renvoi 'true' si la variable 'var' possède une valeur à l'issue d'une declaration avec affectation ou juste une affectation
//
{
    for(Commande commande : resp)
    {
        if((commande.type == commandeType::VAR_DEF || commande.type == commandeType::AFF || commande.type == commandeType ::FUNC_AFF)  && commande.elements[1] == var)
        {
            return true;
        }
    }

    return browsBlocks(flowControl->first, var);
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void Symbole::destroyGraph(Cell *block)
{
    if(block==nullptr)
    {
        return;
    }

    destroyGraph(block->suivant1);
    destroyGraph(block->suivant2);
    delete(block);

}