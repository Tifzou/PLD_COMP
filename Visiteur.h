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


    antlrcpp::Any visitPar(ExprParser::ParContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitDiv(ExprParser::DivContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitAdd(ExprParser::AddContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitSub(ExprParser::SubContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitMult(ExprParser::MultContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitVar(ExprParser::VarContext *ctx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    antlrcpp::Any visitLdconst(ExprParser::LdconstContext *ctx);
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


//-------------------------------------------- Constructeurs - destructeur
    Visiteur (){}
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


protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Symbole symboleManager;

//----------------------------------------------------------- Types privés

};


#endif // VISITEUR_H
