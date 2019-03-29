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
    //symboleManager./****/;
    symboleManager.pushInTemporalCommande(code);
    visit(ctx->ret());
    symboleManager.writeStack(symboleManager.getTemporalCommande()); // Surcharge juste vector<string> commande en argument
    symboleManager.deleteTemporalCommand();                         //deleteTemporalStack() = null;

    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitCode(ExprParser::CodeContext *ctx)
// Algorithme :
//
{
    string typeVar = ctx->typevar()->getText();

    symboleManager.pushInTemporalCommande(typeVar);
    visit(ctx->vari());

    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitRet(ExprParser::RetContext *ctx)
// Algorithme :
//
{
    string nameVar = ctx->VAR()->getText();

    return checkVarDef(nameVar);
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDecVar(ExprParser::DecVarContext *ctx)
// Algorithme :
//
{
    string type;
    for(antlr4::tree::TerminalNode *tmpNode : ctx->VAR())
    {
        string nameVar = tmpNode->getText();

        if (symboleManager.varExist(nameVar))
        {
            commandeType code = commandeType::ERR;
            vector<string> err;
            string error1 = "name of variable '" + nameVar + "' already assigned";
            err.push_back("0321");
            err.push_back(error1);
            symboleManager.deleteTemporalCommand(); //temporalStack = null;
            symboleManager.pushInTemporalCommande(code, err);
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

    return true;

}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDefVar(ExprParser::DefVarContext *ctx)
// Algorithme :
//
{
    string nameVar = ctx->VAR()->getText();

    //Si nameVar et typeVariable existe dans la table des symboles
    if (symboleManager.varExist(nameVar))
    {
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error1 = "name of variable '" + nameVar + "' already assigned";
        err.push_back("0321");
        err.push_back(error1);
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        return false;
    }
    //Si nameVar et typeVariable n'existe pas dans la table des symboles
    else
    {
        commandeType code = commandeType::VAR_DEF;

        symboleManager.pushInTemporalCommande(code); // Surchage pushTemporalStack(vector<string> commande)
        symboleManager.pushInTemporalCommande(nameVar);
        visit(ctx->expr());
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();                       //deleteTemporalStack() = null;
        return true;
    }
}

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
antlrcpp::Any Visiteur::visitDiv(ExprParser::DivContext *ctx)/****/
// Algorithme :
//
{
    symboleManager.pushInTemporalCommande("(");
    if (visit(ctx->expr(0)))
    {
        string divSymb = "/";
        symboleManager.pushInTemporalCommande(divSymb);
        if (visit(ctx->expr(1)))
        {
            symboleManager.pushInTemporalCommande(")");
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
    visit(ctx->expr(0));
    symboleManager.pushInTemporalCommande("+");
    visit(ctx->expr(1));
    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitSub(ExprParser::SubContext *ctx)
// Algorithme :
//
{
    visit(ctx->expr(0));
    symboleManager.pushInTemporalCommande("-");
    visit(ctx->expr(1));
    return true;
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





//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitVar(ExprParser::VarContext *ctx)
// Algorithme :
//
{
    string varName = ctx->VAR()->getText();
    Commande tmpCommande = symboleManager.getTemporalCommande();
    return checkVarDec(varName)&&checkVarDef(varName);
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

//------------------------------------------------------------------------
bool Visiteur::checkVarDec(string varName)
// Algorithme :
//
{
    if (!symboleManager.varExist(varName)) //doit verifier que la variable est bien au dessus et pas en dessous
    {                                     //check if the variable exist
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error1 = "name of variable '" + varName + "' already assigned";
        err.push_back("0321");
        err.push_back(error1);
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        return false;
    }
    else
    {
        symboleManager.pushInTemporalCommande(varName);
        return true;
    }
}


//------------------------------------------------------------------------
bool Visiteur::checkVarDef(string varName)
// Algorithme :
//
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
        return false;
    }
    else
    {
        symboleManager.pushInTemporalCommande(varName);
        return true;
    }
}