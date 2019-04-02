/*************************************************************************
                           PLD_COMP  -  description
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Réalisation de la classe <Visiteur> (fichier Visiteur.cpp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Visiteur.h"


//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitProg(ExprParser::ProgContext *ctx)
// Algorithme :
//
{
    visitChildren(ctx);
    return symboleManager;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitBase(ExprParser::BaseContext *ctx)
// Algorithme :
//
{
    return visitChildren(ctx);
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitCore(ExprParser::CoreContext *ctx)
// Algorithme :
//
{
    for (ExprParser::CodeContext *cd : ctx->code())
    {
        visit(cd);
    }
    commandeType code = commandeType ::RET;
    symboleManager.pushInTemporalCommande(code);
    if((bool)visit(ctx->ret()))
    {
        symboleManager.writeStack(symboleManager.getTemporalCommande());
    }
    symboleManager.deleteTemporalCommand();
    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDecdef(ExprParser::DecdefContext *ctx)
// Algorithme :
//
{
    string typeVar = ctx->typevar()->getText();

    symboleManager.pushInTemporalCommande(typeVar);
    visit(ctx->vari());

    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitAff(ExprParser::AffContext *ctx)
// Algorithme :
//
{

    string varName = ctx->VAR()->getText();
    commandeType code = commandeType ::AFF;
    symboleManager.pushInTemporalCommande(code);

    if(symboleManager.varExist(varName))
    {
        symboleManager.pushInTemporalCommande(" ");
        symboleManager.pushInTemporalCommande(varName);
        visit(ctx->expr());
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
    }
    else
    {
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error3 = "name of variable '" + varName + "' not assigned";
        err.push_back("0323");
        err.push_back(error3);
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
    }

    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitRet(ExprParser::RetContext *ctx)
// Algorithme :
//
{
   visit(ctx->expr());

    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDecVar(ExprParser::DecVarContext *ctx)
// Algorithme :
//
{
    for(antlr4::tree::TerminalNode *tmpNode : ctx->VAR())
    {
        string nameVar = tmpNode->getText();

        if (!checkVarDec(nameVar))
        {
            return false;
        }

        else
        {
            commandeType code = commandeType::VAR_DEC;
            symboleManager.pushInTemporalCommande(code); // Surchage pushTemporalStack(vector<string> commande)
            symboleManager.pushInTemporalCommande(nameVar);
            symboleManager.writeStack(symboleManager.getTemporalCommande());
            symboleManager.popBackLastElemTmpCommande();
        }
    }
    symboleManager.deleteTemporalCommand();

    return true;

}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDefVar(ExprParser::DefVarContext *ctx)
// Algorithme :
//
{
    string nameVar = ctx->VAR()->getText();

    //Si nameVar et typeVariable existe dans la table des symboles
    if (!checkVarDec(nameVar))
    {
        return false;
    }
    //Si nameVar et typeVariable n'existe pas dans la table des symboles
    else
    {
        commandeType code = commandeType::VAR_DEF;
        symboleManager.pushInTemporalCommande(nameVar);
        symboleManager.pushInTemporalCommande(code); // Surchage pushTemporalStack(vector<string> commande)
        if(visit(ctx->expr()))
        {
            symboleManager.writeStack(symboleManager.getTemporalCommande());
        }
        symboleManager.deleteTemporalCommand();                       //deleteTemporalStack() = null;
        return true;
    }
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitExpr(ExprParser::ExprContext *ctx)
// Algorithme :
//
{
    vector<string> tmpElements;
    //specifier dans tmpMatrix type Operation "+"
    for(int i(0); i<ctx->terme().size()-1; i+=2)
    {
        visit(ctx->terme(i));
        //push nomVar dans tmpElement
        visit(ctx->terme(i+1));
        //push nomVar2 dans tmpElement
    }
    //push tmpElement dans tmpMatrix
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitTerme(ExprParser::TermeContext *ctx)
// Algorithme :
//
{
    vector<string> tmpElements;
    //sppecifier dans tmpMatrix type Operation "*"
    for(int i(0); i<ctx->facteur().size()-1; i+=2)
    {
        visit(ctx->facteur(i));
        //push nomVar dans tmpElement
        visit(ctx->facteur(i+1));
        //push nomVar2 dans tmpElement
    }
    //push tmpMatrix
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitFactPar(ExprParser::FactParContext *ctx)
// Algorithme :
//
{

    visit(ctx->expr())
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitFactVar(ExprParser::FactVarContext *ctx)
// Algorithme :
//
{
    string nameVar = ctx->VAR()->getText();
    if(checkVarDef(nameVar))
    {
        //push nameVar dans tmpMatrix
        return true;
    }
    else
    {
        return false;
    }
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitFactInt(ExprParser::FactIntContext *ctx)
// Algorithme :
//
{
    string tmp = ctx->INT()->getText(); //push dans la tmpMatrix
    return true;
}

/*
//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitPar(ExprParser::ParContext *ctx)
// Algorithme :
//
{
    symboleManager.pushInTemporalCommande("(");
    visit(ctx->expr());
    symboleManager.pushInTemporalCommande(")"); //Surcharge

    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDiv(ExprParser::DivContext *ctx)
// Algorithme :
//
{
    if (visit(ctx->expr(0)))
    {
        string divSymb = "/";
        symboleManager.pushInTemporalCommande(divSymb);
        if (visit(ctx->expr(1)))
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitAdd(ExprParser::AddContext *ctx)
// Algorithme :
//
{
    if (visit(ctx->expr(0)))
    {
        string addSymb = "+";
        symboleManager.pushInTemporalCommande(addSymb);
        if (visit(ctx->expr(1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitSub(ExprParser::SubContext *ctx)
// Algorithme :
//
{
    if (visit(ctx->expr(0)))
    {
        string subSymb = "-";
        symboleManager.pushInTemporalCommande(subSymb);
        if (visit(ctx->expr(1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitMult(ExprParser::MultContext *ctx)
// Algorithme :
//
{

    if (visit(ctx->expr(0)))
    {
        string multSymb = "*";
        symboleManager.pushInTemporalCommande(multSymb);
        if (visit(ctx->expr(1)))
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
*/
//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitInt(ExprParser::IntContext *ctx)
// Algorithme :
//
{
    return ctx->TYPEINT()->getText();
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitChar(ExprParser::CharContext *ctx)
// Algorithme :
//
{
    return ctx->TYPECHAR()->getText();
}

 /*
//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitVar(ExprParser::VarContext *ctx)
// Algorithme :
//
{
    string varName = ctx->VAR()->getText();
    return checkVarDef(varName);
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitLdconst(ExprParser::LdconstContext *ctx)
// Algorithme :
//
{
    string value = ctx->INT()->getText();
    symboleManager.pushInTemporalCommande(value); //Surcharge

    return true;
}
*/

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

//------------------------------------------------------------------------
bool Visiteur::checkVarDec(string varName)
// Algorithme : renvoi "true" si la variable avec le nom 'varName' n'est pas déclarée
// De plus, si la variable est déjà déclarée, efface la commande temporelle et la remplit avec une erreur
// Sinon, ajoute la variable dans la pile de la commande
{
    if (symboleManager.varExist(varName)) //doit verifier que la variable est bien au dessus et pas en dessous
    {                                     //check if the variable exist
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error1 = "name of variable '" + varName + "' already assigned";
        err.push_back("0321");
        err.push_back(error1);
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        return false;
    }
    else
    {
        return true;
    }
}


//------------------------------------------------------------------------
bool Visiteur::checkVarDef(string varName)
// Algorithme : renvoi 'true' si la variable 'varName' est bien défini.
// De plus, si la variable n'est pas définit, efface la commande temporelle et la remplit avec une erreur
//Dans le cas contraire, ajoute le nom de la variable dans la pile de la commande
{
    if (!symboleManager.varDef(varName)) //doit verifier que la variable est bien au dessus et pas en dessous
    {                                     //check if the variable exist
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error2 = "variable : '" + varName + "' not defined";
        err.push_back("0322");
        err.push_back(error2);
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        return false;
    }
    else
    {
        return true;
    }
}