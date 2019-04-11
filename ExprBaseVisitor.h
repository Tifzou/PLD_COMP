
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBase(ExprParser::BaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCore(ExprParser::CoreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecdef(ExprParser::DecdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAff(ExprParser::AffContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondif(ExprParser::CondifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElse(ExprParser::IfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleIf(ExprParser::SimpleIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLoop(ExprParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondIf(ExprParser::CondIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondElse(ExprParser::CondElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfCommande(ExprParser::IfCommandeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfRet(ExprParser::IfRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpressionWhile(ExprParser::BoolExpressionWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolExpression(ExprParser::BoolExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEgal(ExprParser::EgalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGe(ExprParser::GeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGt(ExprParser::GtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLe(ExprParser::LeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLt(ExprParser::LtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(ExprParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecVar(ExprParser::DecVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefVar(ExprParser::DefVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(ExprParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerme(ExprParser::TermeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactInt(ExprParser::FactIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactVar(ExprParser::FactVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactPar(ExprParser::FactParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(ExprParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar(ExprParser::CharContext *ctx) override {
    return visitChildren(ctx);
  }


};

