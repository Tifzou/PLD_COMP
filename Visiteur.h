#pragma once

#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"

#include <string>
#include <iostream>

using namespace std;

class Visiteur : public ExprBaseVisitor
{
public:
	antlrcpp::Any visitCore(ExprParser::CoreContext *ctx) override
	{

		string temp = visit(ctx->code());
		string retName = visit(ctx->ret());
		vector<vector<string>> resp;
		vector<string> commande;
		cout << temp << endl;
		int pos = temp.find(";");
		while (pos != -1)
		{
			commande.push_back(temp.substr(0, pos));
			temp.erase(0, pos + 1);
			pos = temp.find(";");
		}
		commande.push_back(temp);
		resp.push_back(commande);

		return resp;
	}

	antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override
	{
		return visit(ctx->expr());
	}

	antlrcpp::Any visitExpr(ExprParser::ExprContext *ctx) override
	{
		return visit(ctx->core());
	}

	antlrcpp::Any visitCode(ExprParser::CodeContext *ctx) override
	{
		string type = visit(ctx->typevar());
		string variable = visit(ctx->vari());
		string ret = type + ";" + variable;
		return ret;
	}

	antlrcpp::Any visitRet(ExprParser::RetContext *ctx) override
	{
		return ctx->VAR()->getText();
	}

	antlrcpp::Any visitAff(ExprParser::AffContext *ctx) override
	{
		string nom = ctx->VAR()->getText();
		string value = ctx->INT()->getText();
		string ret = nom + ";" + value;
		return ret;
	}

	antlrcpp::Any visitInt(ExprParser::IntContext *ctx) override
	{
		return ctx->TYPEINT()->getText();
	}

	antlrcpp::Any visitChar(ExprParser::CharContext *ctx) override
	{
		return ctx->TYPECHAR()->getText();
	}

	/*
    antlrcpp::Any visitFunc(ExprParser::FuncContext *ctx) override
	{
		return (int)visit(ctx->expr(0));
	}
	antlrcpp::Any visitExpr1(ExprParser::Expr1Context *ctx) override
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
	*/
};