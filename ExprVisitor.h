
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

    virtual antlrcpp::Any visitLine(ExprParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitRet(ExprParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitPar(ExprParser::ParContext *context) = 0;

    virtual antlrcpp::Any visitDiv(ExprParser::DivContext *context) = 0;

    virtual antlrcpp::Any visitAdd(ExprParser::AddContext *context) = 0;

    virtual antlrcpp::Any visitSub(ExprParser::SubContext *context) = 0;

    virtual antlrcpp::Any visitMult(ExprParser::MultContext *context) = 0;

    virtual antlrcpp::Any visitVar(ExprParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitLdconst(ExprParser::LdconstContext *context) = 0;

    virtual antlrcpp::Any visitFunction(ExprParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitBrac(ExprParser::BracContext *context) = 0;


};

