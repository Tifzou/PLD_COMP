#pragma once

#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"

using namespace std;

class Visiteur: public ExprBaseVisitor{
public:
	virtual antlrcpp::Any visitConst(ExprParser::ConstContext *ctx) override{
	     return (int) stoi(ctx->INT()getText());
	}
};