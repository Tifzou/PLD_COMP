/*************************************************************************
                           PLD_COMP  -  description

    Classe permettant de parcourir l'arbre généré par la grammaire afin
    de créer les temporals et les variables utiles à l'IR
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
//      Permet de parcourir l'arbre généré par la grammaire afin
//      de créer les temporals et les variables utiles à l'IR
//
//------------------------------------------------------------------------

class Visiteur : public ExprBaseVisitor
{
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi :
    //      Surchage du constructeur de base
    // Contrat :
    //
    Visiteur (){}

    // Mode d'emploi :
    //      Surchagre du constructeur pour indiquer si l'on souhaite afficher les erreurs d'analyse
    // Contrat :
    //
    Visiteur (bool showErrorAnalyse): showError(showErrorAnalyse){}

    // Mode d'emploi :
    //      Destructeur par défaut
    // Contrat :
    //
    virtual ~Visiteur(){}

//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //      Permet d'analyser le noeud racine de l'arbre
    // Contrat :
    //
    antlrcpp::Any visitProg(ExprParser::ProgContext *ctx);

    // TODO
    // Mode d'emploi :
    //      Permet d'analyser le noeud Base
    // Contrat :
    //
    antlrcpp::Any visitBase(ExprParser::BaseContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds Function
    // Contrat :
    //
    antlrcpp::Any visitFunction(ExprParser::FunctionContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser le noeud de la fonciton main
    // Contrat :
    //
    antlrcpp::Any visitMainFunction(ExprParser::MainFunctionContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds Param pour les paramètres des fonctions
    // Contrat :
    //
    antlrcpp::Any visitParam(ExprParser::ParamContext *ctx);

    // TODO refaire commentaire
    // Mode d'emploi :
    //      Permet d'analyser les noeuds Param pour les paramètres des fonctions
    // Contrat :
    //
    antlrcpp::Any visitAfffunc(ExprParser::AfffuncContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les appels de fonction
    // Contrat :
    //
    antlrcpp::Any visitCallfunc(ExprParser::CallfuncContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les blocs de code
    // Contrat :
    //
    antlrcpp::Any visitCore(ExprParser::CoreContext *ctx);

    //TODO terminer de commenter le .h
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
    antlrcpp::Any visitAdd(ExprParser::AddContext *ctx)
    {
        return "+";
    }

    // Mode d'emploi :
    //
    // Contrat :
    //
    antlrcpp::Any visitSub(ExprParser::SubContext *ctx)
    {
        return "-";
    }

    // Mode d'emploi :
    //
    // Contrat :
    //
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
    //      Permet d'analyser les noeuds correspondant au corps du IF
    // Contrat :
    //
    antlrcpp::Any visitIfCore(ExprParser::IfCoreContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les comparaisons ==
    // Contrat :
    //
    antlrcpp::Any visitEgal(ExprParser::EgalContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les comparaisons >=
    // Contrat :
    //
    antlrcpp::Any visitGe(ExprParser::GeContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les comparaisons >
    // Contrat :
    //
    antlrcpp::Any visitGt(ExprParser::GtContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les comparaisons <=
    // Contrat :
    //
    antlrcpp::Any visitLe(ExprParser::LeContext *ctx);

    // Mode d'emploi :
    //      Permet d'analyser les noeuds pour les comparaisons <
    // Contrat :
    //
    antlrcpp::Any visitLt(ExprParser::LtContext *ctx);

    // Mode d'emploi :
    //      Permet d'obtenir l'IR associé au visiteur
    // Contrat :
    //
    Symbole getSymboleManager();

    // Mode d'emploi :
    //      Permet de vérifier si une erreur est apparue
    // Contrat :
    //
    bool checkError(){ return hasError;};

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    // Mode d'emploi :
    //
    // Contrat :
    //
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

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Symbole symboleManager;
    bool showError=false;
    bool hasError=false;
//----------------------------------------------------------- Types privés

};


#endif // VISITEUR_H
