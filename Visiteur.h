#pragma once

#include "antlr4-runtime/antlr4-runtime.h"
#include "ExprBaseVisitor.h"

#include <string>
#include <iostream>
#include <map>

using namespace std;

class Visiteur : public ExprBaseVisitor
{
  public:
	antlrcpp::Any visitCore(ExprParser::CoreContext *ctx) override
	{
		map<string, string> varTable;

		vector<ExprParser::CodeContext *> pileInstruction = ctx->code();
		vector<vector<string>> resp;
		for (ExprParser::CodeContext *e : pileInstruction)
		{
			string temp = visit(e);

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
		}
		cout << "test1" << endl;

		for (map<string, string>::iterator it = varTable.begin(); it != varTable.end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}
		cout << "test2" << endl;

		string retName = visit(ctx->ret());
		cout << varTable[retName] << endl; // comportement très etrange

		if (varTable.find(retName) != varTable.end())
		{
			cout << "test" << endl;

			vector<string> retCommande;
			retCommande.push_back(string("return"));
			retCommande.push_back(retName);

			resp.push_back(retCommande);
			cout << "test3" << endl;

			for (auto i : resp)
			{
				for (auto j : i)
				{
					cout << j << " ";
				}
				cout << endl;
			}
			cout << "test4" << endl;
			return resp;
		}
		else
		{
			return "variable doesn't found error 404";
		}
	}

	antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override
	{
		return visit(ctx->base());
	}

	antlrcpp::Any visitBase(ExprParser::BaseContext *ctx) override
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

	antlrcpp::Any visitExpression(ExprParser::ExpressionContext *ctx) override
	{
		return visit(ctx->expr());
	}
	antlrcpp::Any visitInt(ExprParser::IntContext *ctx) override
	{
		return ctx->TYPEINT()->getText();
	}

	antlrcpp::Any visitChar(ExprParser::CharContext *ctx) override
	{
		return ctx->TYPECHAR()->getText();
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
};