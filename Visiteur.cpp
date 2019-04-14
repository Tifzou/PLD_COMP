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

/*---------- Réalisation de la classe <Visiteur> (fichier Visiteur.cpp) ------------*/
/*---------------------------------------------------------------- INCLUDE*/
/*-------------------------------------------------------- Include système*/
#include <iostream>

/*------------------------------------------------------ Include personnel*/
#include "Visiteur.h"
/*----------------------------------------------------------- Types privés*/
/*----------------------------------------------------------------- PUBLIC*/
/*----------------------------------------------------- Méthodes publiques*/
/*------------------------------------------------------------------------*/
antlrcpp::Any Visiteur::visitProg(ExprParser::ProgContext *ctx)
// Algorithme :
//
{
    return visitChildren(ctx);
}
/*------------------------------------------------------------------------*/
antlrcpp::Any Visiteur::visitBase(ExprParser::BaseContext *ctx)
/* Algorithme : */
{
    return visitChildren(ctx);
}
/*------------------------------------------------------------------------*/
antlrcpp::Any Visiteur::visitFunction(ExprParser::FunctionContext *ctx)
/* Algorithme : */
{
    string functName = ctx->VAR()->getText();
    if (!checkFunctDec(functName)) // si function existe deja
    {
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : name of function '"<<functName<<"' already assigne !"<<endl;
        }
        hasError=true;
        return false;
    }
    //Si functName n'existe pas dans la table des fonctions
    else
    {
        cout << "function doesn't exist, let's create it" << endl;
        symboleManager.createFunction(functName);
        commandeType code = commandeType::FUNC;

        symboleManager.pushInTemporalCommande(code); // Surchage pushTemporalStack(vector<string> commande)
        symboleManager.pushInTemporalCommande(functName);

        visit(ctx->param());


        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        visit(ctx->core());
        return true;
    }
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitMainFunction(ExprParser::MainFunctionContext *ctx)
// Algorithme :
//
{
    commandeType code = commandeType::MAIN;
    symboleManager.pushInTemporalCommande(code); // Surchage pushTemporalStack(vector<string> commande)
    // TODO add parameter visit
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    symboleManager.deleteTemporalCommand();
    visit(ctx->core());
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitParam(ExprParser::ParamContext *ctx)
// Algorithme :
//
{
    for(antlr4::tree::TerminalNode *tn:ctx->VAR())
    {
        string varName = tn->getText();
        symboleManager.pushInTemporalCommande(varName);
    }
    // Fixme : if name already exists, break and error

    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitAfffunc(ExprParser::AfffuncContext *ctx)
// Algorithme : renvoi "true" si la variable avec le nom 'varName' n'est pas déclarée
//              De plus, si la variable est déjà déclarée, efface la commande temporelle et la remplit avec une erreur
//              Sinon, ajoute la variable dans la pile de la commande
{
    string funcName = ctx->VAR()[1]->getText();
    commandeType code = commandeType::FUNC_AFF;
    string retVar = ctx->VAR()[0]->getText();
    cout << "ret value dans visiteur : " << retVar << endl;
    if(symboleManager.functExist(funcName))
    {
        cout << "la fonction existe" << endl;
        /*symboleManager.pushInTemporalCommande(code);
        symboleManager.pushInTemporalCommande(funcName);
        symboleManager.pushInTemporalCommande(retVar);
        int nbParam = ctx->VAR().size();
        for (int i = 1; i<=nbParam ; i++)
        {
            symboleManager.pushInTemporalCommande(ctx->VAR(i));
        }
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();*/
    }
    else
    {
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error3 = "name of function '" + funcName + "' not assigned";
        err.push_back("0323");
        err.push_back(error3);
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : Name of function '"<<funcName<<"' not assigned !"<<endl;
        }
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
    }

    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitCallfunc(ExprParser::CallfuncContext *ctx)
// Algorithme :
//
{
    string funcName = ctx->VAR()[0]->getText();

    if(symboleManager.functExist(funcName))
    {
        cout << "the function exists so we can call it" << endl;
        /*commandeType code = commandeType::FUNC_CALL;
        symboleManager.pushInTemporalCommande(code);
        symboleManager.pushInTemporalCommande(funcName);
        int nbParam = ctx->VAR().size();
        for (int i = 1; i<=nbParam ; i++)
        {
            symboleManager.pushInTemporalCommande(ctx->VAR(i));
        }
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();*/
    }
    else{
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error1 = "name of function '" + funcName + "' already assigned";
        err.push_back("0667");
        err.push_back(error1);
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : Name of function '"<<funcName<<"' already assigned !"<<endl;
        }
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        hasError=true;
        return false;

    }


    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitLvalue(ExprParser::LvalueContext *ctx)
// Algorithme :
//
{
    ExprParser::ExprlContext * expr1=ctx->exprl();

    //string varName = expr1->VAR()->getText();

    commandeType code = commandeType::AFFL;
    symboleManager.pushInTemporalCommande(code);

    /*if(symboleManager.varExist(varName)){
        vector<ExprParser::ExprContext *> listExpr1=expr1->expr();
        unsigned long size=listExpr1.size();
        for(int i(0); i<size; i++)
        {
            ExprParser::ExprContext* e=listExpr1[i];
            if (!visitExpr(e))
            {
                return false;
            }

            symboleManager.pushInTemporalCommande(symboleManager.getTemporalExpression()->back().elements[1]);
            symboleManager.writeStack(*symboleManager.getTemporalExpression());
            symboleManager.deleteTemporalExpression();
            symboleManager.writeStack(symboleManager.getTemporalCommande());
            symboleManager.deleteTemporalCommand();
        }
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
        symboleManager.deleteTemporalExpression();
    }*/

    return true;
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
    commandeType code = commandeType::RET;
    symboleManager.pushInTemporalCommande(code);
    if ((bool)visit(ctx->ret()))
    {
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        if(symboleManager.getFlowControl()->first== nullptr)
        {
            symboleManager.pushIntoFlowControl();
        }
        else
        {
            symboleManager.pushLastBlockIntoFlowControl();
        }
        symboleManager.deleteTemporalCommand();
        return true;
    }

    hasError=true;
    //TODO check message
    if(showError){
        cerr<<"Line "<<ctx->start->getLine()<<" : the following block is not closed !"<<endl;
    }
    return false;
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
        symboleManager.pushInTemporalCommande(symboleManager.retrieveVarType(varName));
        symboleManager.pushInTemporalCommande(varName);
        if(!visit(ctx->expr()))
        {
            //TODO check message
            if(showError){
                cerr<<"Line "<<ctx->start->getLine()<<" : the following expression is not valid !"<<endl;
            }
            hasError=true;
            return false;
        }
        symboleManager.pushInTemporalCommande(symboleManager.getTemporalExpression()->back().elements[1]);
        symboleManager.writeStack(*symboleManager.getTemporalExpression());
        symboleManager.deleteTemporalExpression();
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
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : Name of variable '"<<varName<<"' not assigned !"<<endl;
        }
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        symboleManager.deleteTemporalExpression();
    }

    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitRet(ExprParser::RetContext *ctx)
// Algorithme :
//
{
    if(visit(ctx->expr()))
    {
        symboleManager.pushInTemporalCommande(symboleManager.getTemporalExpression()->back().elements[1]);
        symboleManager.writeStack(*symboleManager.getTemporalExpression());
        symboleManager.deleteTemporalExpression();
        return true;
    }
    hasError=true;
    //TODO check message
    if(showError){
        cerr<<"Line "<<ctx->start->getLine()<<" : the return expression is invalid !"<<endl;
    }
    return false;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitDecVar(ExprParser::DecVarContext *ctx)
// Algorithme :
//
{
    for (antlr4::tree::TerminalNode *tmpNode : ctx->VAR())
    {
        string nameVar = tmpNode->getText();

        if (!checkVarDec(nameVar))
        {
            if(showError){
                cerr<<"Line "<<ctx->start->getLine()<<" : Name of variable '"<<nameVar<<"' already assigned !"<<endl;
            }
            hasError=true;
            return false;
        }else
        {
            symboleManager.createVar(nameVar);
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
        symboleManager.deleteTemporalExpression();

        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : Name of variable '"<<nameVar<<"' already assigned !"<<endl;
        }

        hasError=true;
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
            symboleManager.createVar(nameVar);
            symboleManager.pushInTemporalCommande(symboleManager.getTemporalExpression()->back().elements[1]);
            symboleManager.writeStack(*symboleManager.getTemporalExpression());
            symboleManager.deleteTemporalExpression();
            symboleManager.writeStack(symboleManager.getTemporalCommande());
            symboleManager.deleteTemporalCommand();
            return true;
        }
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the definition of "<<nameVar<<" is invalid !"<<endl;
        }
        hasError=true;
        return false;
    }
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitExpr(ExprParser::ExprContext *ctx)
// Algorithme :
//
{
    for(int i(1); i<ctx->terme().size(); i++)
    {
        vector<string> commande;

        if(i==1&&!visit(ctx->terme(i-1)))
        {
            hasError=true;
            //TODO check message
            if(showError){
                cerr<<"Line "<<ctx->start->getLine()<<" : the last factor is invalid !"<<endl;
            }
            return false;
        }
        string nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
        if(!visit(ctx->terme(i)))
        {
            hasError=true;
            //TODO check message
            if(showError){
                cerr<<"Line "<<ctx->start->getLine()<<" : one of the factor used is invalid !"<<endl;
            }
            return false;
        }
        string nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
        cout<<nomVar1<<" "<<nomVar2<<endl;
        string tempVar = "!t" + to_string(symboleManager.createTemporalVar());

        commande.push_back(symboleManager.retrieveVarType(nomVar1));
        commande.push_back(tempVar);
        commande.push_back(nomVar1);
        commande.push_back(ctx->operatorAddSub(i-1)->getText());
        commande.push_back(nomVar2);

        symboleManager.pushTemporalMatriceVari(commande);
    }

    if(ctx->terme().size()==1)
    {
        return visit(ctx->terme(ctx->terme().size()-1));
    }

    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitTerme(ExprParser::TermeContext *ctx)
// Algorithme :
//
{

    for(int i(1); i<ctx->facteur().size(); i++)
    {
        vector<string> commande;
        if(i==1&&!visit(ctx->facteur(i-1)))
        {
            hasError=true;

            //TODO check message
            if(showError){
                cerr<<"Line "<<ctx->start->getLine()<<" : one of the factor used is invalid !"<<endl;
            }
            return false;
        }
        string nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
        if(!visit(ctx->facteur(i)))
        {
            hasError=true;
            //TODO check message
            if(showError){
                cerr<<"Line "<<ctx->start->getLine()<<" : one of the factor used is invalid !"<<endl;
            }
            return false;
        }
        string nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
        string tempVar = "!t" + to_string(symboleManager.createTemporalVar());

        commande.push_back(symboleManager.retrieveVarType(nomVar1));
        commande.push_back(tempVar);
        commande.push_back(nomVar1);
        commande.push_back("*");
        commande.push_back(nomVar2);

        symboleManager.pushTemporalMatriceVari(commande);
    }

    if(ctx->facteur().size()==1)
    {
        return visit(ctx->facteur(ctx->facteur().size()-1));
    }

    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitFactPar(ExprParser::FactParContext *ctx)
// Algorithme :
//
{
    return visit(ctx->expr());
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitFactVar(ExprParser::FactVarContext *ctx)
// Algorithme :
//
{
    vector<string> commande;
    string var = ctx->VAR()->getText();
    if (symboleManager.varDef(var))
    {
        commande.push_back(symboleManager.retrieveVarType(var));
        string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
        commande.push_back(tempVar);
        commande.push_back(ctx->VAR()->getText());
        //symboleManager.pushTemporalMatriceVari(commandeType::VAR_DEF,commande);
        symboleManager.pushTemporalMatriceVari(commande);
        return true;
    }
    else
    {
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error2 = "variable : '" + var + "' not defined";
        err.push_back("0322");
        err.push_back(error2);

        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : Variable '"<<var<<"' not defined !"<<endl;
        }
        symboleManager.deleteTemporalExpression(); //temporalStack = null;

        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        hasError=true;
        return false;
    }
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitFactInt(ExprParser::FactIntContext *ctx)
// Algorithme :
//
{
    vector<string> commande;
    commande.push_back("int");
    commande.push_back("!t"+to_string(symboleManager.createTemporalVar()));
    commande.push_back(ctx->INT()->getText());
    //symboleManager.pushTemporalMatriceVari(commandeType::VAR_DEF,commande);
    symboleManager.pushTemporalMatriceVari(commande);
    return true;
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
antlrcpp::Any Visiteur::visitCondif(ExprParser::CondifContext *ctx)
// Algorithme :
//
{
    return visit(ctx->condition());
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitIfElse(ExprParser::IfElseContext *ctx)
// Algorithme :
//
{

    commandeType code = commandeType::IF;
    symboleManager.pushInTemporalCommande(code);
    symboleManager.writeStack(symboleManager.getTemporalCommande());

    if(visit(ctx->boolExpression()))
    {
        //symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.pushIntoFlowControl();
    }
    else
    {
        hasError=true;

        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the boolean expression is invalid !"<<endl;
        }
        return false;
    }
    Cell* curBlock=symboleManager.getFlowControl()->last;
    //On visite le block "if" qui s'executera si le predicat est verifié
    if(visit(ctx->coreIf()))
    {
        //symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.pushIfIntoFlowControl(curBlock);

    }
    else
    {
        hasError=true;

        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the block of if structure is invalid !"<<endl;
        }
        return false;
    }


    //On visit le block "else" qui s'executera si le predicat est faux
    if(visit(ctx->coreElse()))
    {
        //symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.pushElseIntoFlowControl(curBlock);
    }
    else
    {
        hasError=true;
        return false;
    }
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitSimpleIf(ExprParser::SimpleIfContext *ctx){
// Algorithme :
//

    commandeType code = commandeType::IF;
    symboleManager.pushInTemporalCommande(code);
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    if(visit(ctx->boolExpression()))
    {
        //symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.pushIntoFlowControl();
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the boolean expression is invalid !"<<endl;
        }
        return false;
    }

    //On visite le block "if" qui s'executera si le predicat est verifié
    Cell* curBlock=symboleManager.getFlowControl()->last;
    if(visit(ctx->coreIf()))
    {
        //symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.pushIfIntoFlowControl(curBlock);
        symboleManager.pushElseIntoFlowControl(curBlock);
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the content of the if block is invalid !"<<endl;
        }
        return false;
    }
    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitGe(ExprParser::GeContext *ctx)
// Algorithme :
//
{
    cout<<"test predicat"<<endl;
    string nomVar1;
    string nomVar2;
    if(visit(ctx->expr(0)))
    {
        nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;

        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }

    if(visit(ctx->expr(1)))
    {
        nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }
    string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
    symboleManager.pushInTemporalCommande(commandeType::CONDITION);
    symboleManager.pushInTemporalCommande("bool");
    symboleManager.pushInTemporalCommande(tempVar);
    symboleManager.pushInTemporalCommande(nomVar1);
    symboleManager.pushInTemporalCommande(">=");
    symboleManager.pushInTemporalCommande(nomVar2);
    symboleManager.writeStack(*symboleManager.getTemporalExpression());
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitGt(ExprParser::GtContext *ctx)
// Algorithme :
//
{
    string nomVar1;
    string nomVar2;
    if(visit(ctx->expr(0)))
    {
        nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }

    if(visit(ctx->expr(1)))
    {
        nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }
    string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
    symboleManager.pushInTemporalCommande(commandeType::CONDITION);
    symboleManager.pushInTemporalCommande("bool");
    symboleManager.pushInTemporalCommande(tempVar);
    symboleManager.pushInTemporalCommande(nomVar1);
    symboleManager.pushInTemporalCommande(">");
    symboleManager.pushInTemporalCommande(nomVar2);
    symboleManager.writeStack(*symboleManager.getTemporalExpression());
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitLe(ExprParser::LeContext *ctx)
// Algorithme :
//
{
    string nomVar1;
    string nomVar2;
    if(visit(ctx->expr(0)))
    {
        nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }

    if(visit(ctx->expr(1)))
    {
        nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }
    string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
    symboleManager.pushInTemporalCommande(commandeType::CONDITION);
    symboleManager.pushInTemporalCommande("bool");
    symboleManager.pushInTemporalCommande(tempVar);
    symboleManager.pushInTemporalCommande(nomVar1);
    symboleManager.pushInTemporalCommande("<=");
    symboleManager.pushInTemporalCommande(nomVar2);
    symboleManager.writeStack(*symboleManager.getTemporalExpression());
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitLt(ExprParser::LtContext *ctx)
// Algorithme :
//
{

    string nomVar1;
    string nomVar2;
    if(visit(ctx->expr(0)))
    {
        nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }

    if(visit(ctx->expr(1)))
    {
        nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }
    string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
    symboleManager.pushInTemporalCommande(commandeType::CONDITION);
    symboleManager.pushInTemporalCommande("bool");
    symboleManager.pushInTemporalCommande(tempVar);
    symboleManager.pushInTemporalCommande(nomVar1);
    symboleManager.pushInTemporalCommande("<");
    symboleManager.pushInTemporalCommande(nomVar2);
    symboleManager.writeStack(*symboleManager.getTemporalExpression());
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    return true;
}


//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitEgal(ExprParser::EgalContext *ctx)
// Algorithme :
//
{
    cout<<"test predicat"<<endl;
    string nomVar1;
    string nomVar2;
    if(visit(ctx->expr(0)))
    {
        nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }

    if(visit(ctx->expr(1)))
    {
        nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }
    string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
    symboleManager.pushInTemporalCommande(commandeType::CONDITION);
    symboleManager.pushInTemporalCommande("bool");
    symboleManager.pushInTemporalCommande(tempVar);
    symboleManager.pushInTemporalCommande(nomVar1);
    symboleManager.pushInTemporalCommande("==");
    symboleManager.pushInTemporalCommande(nomVar2);
    symboleManager.writeStack(*symboleManager.getTemporalExpression());
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitNEgal(ExprParser::NegalContext *ctx)
// Algorithme :
//
{
    cout<<"test predicat"<<endl;
    string nomVar1;
    string nomVar2;
    if(visit(ctx->expr(0)))
    {
        nomVar1=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }

    if(visit(ctx->expr(1)))
    {
        nomVar2=symboleManager.getTemporalExpression()->back().elements[1];
    }
    else
    {
        hasError=true;
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : one of the expression used is invalid !"<<endl;
        }
        return false;
    }
    string tempVar = "!t" + to_string(symboleManager.createTemporalVar());
    symboleManager.pushInTemporalCommande(commandeType::CONDITION);
    symboleManager.pushInTemporalCommande("bool");
    symboleManager.pushInTemporalCommande(tempVar);
    symboleManager.pushInTemporalCommande(nomVar1);
    symboleManager.pushInTemporalCommande("!=");
    symboleManager.pushInTemporalCommande(nomVar2);
    symboleManager.writeStack(*symboleManager.getTemporalExpression());
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    return true;
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitBoolExpressionWhile(ExprParser::BoolExpressionWhileContext *ctx)
// Algorithme :
//
{
    symboleManager.pushInTemporalCommande(commandeType::CONDITIONWHILE);

    return visitChildren(ctx);
}

//------------------------------------------------------------------------
antlrcpp::Any Visiteur::visitWhileLoop(ExprParser::WhileLoopContext *ctx)
// Algorithme :
//
{
    commandeType code = commandeType::WHILE;
    symboleManager.pushInTemporalCommande(code);
    symboleManager.writeStack(symboleManager.getTemporalCommande());
    if (visit(ctx->boolExpressionWhile()))
    {
        symboleManager.pushIntoFlowControl();
    }
    else
    {
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the boolean expression of while loop is invalid !"<<endl;
        }
        return false;
    }

    if (visit(ctx->coreIf()))
    {
        symboleManager.pushIntoFlowControl();
        return true;
    }
    else
    {
        //TODO check message
        if(showError){
            cerr<<"Line "<<ctx->start->getLine()<<" : the content of the while loop is invalid !"<<endl;
        }
        return false;
    }
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

//------------------------------------------------------------------------
Symbole Visiteur::getSymboleManager()
// Algorithme :
//
{
    return symboleManager;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

//------------------------------------------------------------------------
bool Visiteur::checkVarDec(string varName)
// Algorithme : renvoi "true" si la variable avec le nom 'varName' n'est pas déclarée
//              De plus, si la variable est déjà déclarée, efface la commande temporelle et la remplit avec une erreur
//              Sinon, ajoute la variable dans la pile de la commande
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
        hasError=true;
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
//              De plus, si la variable n'est pas définit, efface la commande temporelle et la remplit avec une erreur
//              Dans le cas contraire, ajoute le nom de la variable dans la pile de la commande
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
        hasError=true;

        return false;
    }
    else
    {
        return true;
    }
}

//------------------------------------------------------------------------
bool Visiteur::checkFunctDec(string functName)
// Algorithme : renvoi "true" si la variable avec le nom 'varName' n'est pas déclarée
//              De plus, si la variable est déjà déclarée, efface la commande temporelle et la remplit avec une erreur
//              Sinon, ajoute la variable dans la pile de la commande
{
    if (symboleManager.functExist(functName)) //doit verifier que la fonction est bien au dessus et pas en dessous
    {                                     //check if the function exists
        commandeType code = commandeType::ERR;
        vector<string> err;
        string error1 = "name of function '" + functName + "' already assigned";
        err.push_back("0666");
        err.push_back(error1);
        symboleManager.deleteTemporalCommand(); //temporalStack = null;
        symboleManager.pushInTemporalCommande(code, err);
        symboleManager.writeStack(symboleManager.getTemporalCommande());
        symboleManager.deleteTemporalCommand();
        hasError=true;
        return false;
    }
    else
    {
        return true;
    }
}