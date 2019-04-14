/*************************************************************************
                           PLD_COMP  -  description
                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/

//---------- Interface de la classe <Visiteur> (fichier Visiteur.h) ----------------
#if ! defined ( VISITEUR_H )
#define VISITEUR_H

//--------------------------------------------------- Interfaces utilisées

#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"
#include "Symbole.h"
#include <string>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Visiteur>
//
//
//------------------------------------------------------------------------

class Visiteur : public ExprBaseVisitor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //
    // Contrat :
    //
    antlrcpp::Any visitProg(ExprParser::ProgContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitBase(ExprParser::BaseContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitFunction(ExprParser::FunctionContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitMainFunction(ExprParser::MainFunctionContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitParam(ExprParser::ParamContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitAfffunc(ExprParser::AfffuncContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitCallfunc(ExprParser::CallfuncContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitCore(ExprParser::CoreContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitDecdef(ExprParser::DecdefContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitAff(ExprParser::AffContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitRet(ExprParser::RetContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitDecVar(ExprParser::DecVarContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitDefVar(ExprParser::DefVarContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitExpr(ExprParser::ExprContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitTerme(ExprParser::TermeContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitFacteur(ExprParser::FacteurContext *ctx) ;
    
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitAdd(ExprParser::AddContext *ctx)
    //
    // Contrat :
    //
    {
        return "+";
    }

    antlrcpp::Any visitSub(ExprParser::SubContext *ctx)
    //
    // Contrat :
    //
    {
        return "-";
    }

    antlrcpp::Any visitFactPar(ExprParser::FactParContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


    antlrcpp::Any visitFactVar(ExprParser::FactVarContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitFactInt(ExprParser::FactIntContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitInt(ExprParser::IntContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitChar(ExprParser::CharContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitCondif(ExprParser::CondifContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitIfElse(ExprParser::IfElseContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitSimpleIf(ExprParser::SimpleIfContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitIfCore(ExprParser::IfCoreContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitEgal(ExprParser::EgalContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitGe(ExprParser::GeContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitGt(ExprParser::GtContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitLe(ExprParser::LeContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitLt(ExprParser::LtContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Visiteur (){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    Visiteur (bool showErrorAnalyse): showError(showErrorAnalyse){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Visiteur(){}
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    bool checkVarDec(string varName);
    // Mode d'emploi :
    //
    // Contrat :
    //


    bool checkVarDef(string varName);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool checkFunctDec(string functName);
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Symbole symboleManager;
    bool showError=false;
//----------------------------------------------------------- Types privés

};


#endif // VISITEUR_H
