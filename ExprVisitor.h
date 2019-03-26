
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

    virtual antlrcpp::Any visitExpr(ExprParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitCore(ExprParser::CoreContext *context) = 0;

    virtual antlrcpp::Any visitCode(ExprParser::CodeContext *context) = 0;


};

