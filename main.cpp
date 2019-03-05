#include <iostream>
#include <fstream>

#include "antlr4-cpp-runtime-4.7.2-macos/antlr4-runtime/antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseVisitor.h"
#include "Visiteur.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ifstream file;
		file.open(argv[1]);
		//file.open("index.cpp");
		ANTLRInputStream input(file);
		ExprLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		ExprParser parser(&tokens);
		tree::ParseTree *tree = parser.prog();

		Visiteur visitor;
		int resultat = (int)visitor.visit(tree);
		cout << "Résultat " << resultat << endl;

		return 0;
	}
	else
	{
		cerr << "USAGE: " << argv[0] << "<FILENAME.c>" << endl;
		return 1;
	}
}
