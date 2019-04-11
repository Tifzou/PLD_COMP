
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitBase(ExprParser::BaseContext *context) = 0;

    virtual antlrcpp::Any visitCore(ExprParser::CoreContext *context) = 0;

    virtual antlrcpp::Any visitDecdef(ExprParser::DecdefContext *context) = 0;

    virtual antlrcpp::Any visitAff(ExprParser::AffContext *context) = 0;

    virtual antlrcpp::Any visitCondif(ExprParser::CondifContext *context) = 0;

    virtual antlrcpp::Any visitIfElse(ExprParser::IfElseContext *context) = 0;

    virtual antlrcpp::Any visitSimpleIf(ExprParser::SimpleIfContext *context) = 0;

    virtual antlrcpp::Any visitWhileLoop(ExprParser::WhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitCondIf(ExprParser::CondIfContext *context) = 0;

    virtual antlrcpp::Any visitCondElse(ExprParser::CondElseContext *context) = 0;

    virtual antlrcpp::Any visitIfCommande(ExprParser::IfCommandeContext *context) = 0;

    virtual antlrcpp::Any visitIfRet(ExprParser::IfRetContext *context) = 0;

    virtual antlrcpp::Any visitBoolExpressionWhile(ExprParser::BoolExpressionWhileContext *context) = 0;

    virtual antlrcpp::Any visitBoolExpression(ExprParser::BoolExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEgal(ExprParser::EgalContext *context) = 0;

    virtual antlrcpp::Any visitGe(ExprParser::GeContext *context) = 0;

    virtual antlrcpp::Any visitGt(ExprParser::GtContext *context) = 0;

    virtual antlrcpp::Any visitLe(ExprParser::LeContext *context) = 0;

    virtual antlrcpp::Any visitLt(ExprParser::LtContext *context) = 0;

    virtual antlrcpp::Any visitRet(ExprParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitDecVar(ExprParser::DecVarContext *context) = 0;

    virtual antlrcpp::Any visitDefVar(ExprParser::DefVarContext *context) = 0;

    virtual antlrcpp::Any visitExpr(ExprParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitTerme(ExprParser::TermeContext *context) = 0;

    virtual antlrcpp::Any visitFactInt(ExprParser::FactIntContext *context) = 0;

    virtual antlrcpp::Any visitFactVar(ExprParser::FactVarContext *context) = 0;

    virtual antlrcpp::Any visitFactPar(ExprParser::FactParContext *context) = 0;

    virtual antlrcpp::Any visitInt(ExprParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitChar(ExprParser::CharContext *context) = 0;


};

