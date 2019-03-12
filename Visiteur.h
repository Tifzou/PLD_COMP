#pragma once

#include "antlr4-runtime/antlr4-runtime.h"
#include "ExprBaseVisitor.h"

using namespace std;

class Visiteur : public ExprBaseVisitor
{
   public:
	antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override
	{
		return (int)visit(ctx->expr());
	}

	antlrcpp::Any visitAdd(ExprParser::AddContext *ctx) override
	{
		return (int)visit(ctx->expr(0)) +
			  (int)visit(ctx->expr(1));
	}

	antlrcpp::Any visitMult(ExprParser::MultContext *ctx) override
	{
		return (int)visit(ctx->expr(0)) *
			  (int)visit(ctx->expr(1));
	}

	virtual antlrcpp::Any visitLdconst(ExprParser::LdconstContext *ctx) override
	{
		return (int)stoi(ctx->INT()->getText());
	}
};