#pragma once

#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"

#include <list>
#include <string>

using namespace std;

class Visiteur : public ExprBaseVisitor
{
   public:

	antlrcpp::Any visitCode(ExprParser::CodeContext *ctx) override
	{
		return (int)stoi(ctx->INT()->getText());
	}

	antlrcpp::Any visitCore(ExprParser::CoreContext *ctx) override
	{
		return (int)visit(ctx->code());
	}

	antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override
	{
		return (int)visit(ctx->expr());
	}

	antlrcpp::Any visitExpr(ExprParser::ExprContext *ctx) override
	{
		return (int)visit(ctx->core());
	}
	/*antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override
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
	}*/

   private:
	list<string> cmdAsm;
};
