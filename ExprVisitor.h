
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

    virtual antlrcpp::Any visitCode(ExprParser::CodeContext *context) = 0;

    virtual antlrcpp::Any visitRet(ExprParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitDec(ExprParser::DecContext *context) = 0;

    virtual antlrcpp::Any visitAff(ExprParser::AffContext *context) = 0;

    virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPar(ExprParser::ParContext *context) = 0;

    virtual antlrcpp::Any visitDiv(ExprParser::DivContext *context) = 0;

    virtual antlrcpp::Any visitAdd(ExprParser::AddContext *context) = 0;

    virtual antlrcpp::Any visitSub(ExprParser::SubContext *context) = 0;

    virtual antlrcpp::Any visitMult(ExprParser::MultContext *context) = 0;

    virtual antlrcpp::Any visitVar(ExprParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitLdconst(ExprParser::LdconstContext *context) = 0;

    virtual antlrcpp::Any visitInt(ExprParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitChar(ExprParser::CharContext *context) = 0;


};

