#pragma once

#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"

using namespace std;

class Visiteur: public ExprBaseVisitor{
public:
	antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override 
	{
		return (int) visit(ctx->expr());
	}

	virtual antlrcpp::Any visitConst(ExprParser::ConstContext *ctx) override
	{
	     return (int) stoi(ctx->INT()getText());
	}
};