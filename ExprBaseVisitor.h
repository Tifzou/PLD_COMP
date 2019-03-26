
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

  virtual antlrcpp::Any visitCode(ExprParser::CodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(ExprParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDec(ExprParser::DecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAff(ExprParser::AffContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPar(ExprParser::ParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiv(ExprParser::DivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd(ExprParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub(ExprParser::SubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMult(ExprParser::MultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(ExprParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLdconst(ExprParser::LdconstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(ExprParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar(ExprParser::CharContext *ctx) override {
    return visitChildren(ctx);
  }


};

