#include<iostream>
#include <fstream>

#include"antlr4-runtime.h"
#include"ExprLexer.h"
#include"ExprParser.h"
#include"ExprBaseVisitor.h"
#include"Calc.h"

using namespace antlr4;
using namespace std;

int main(int argc, char* argv[]) 
{
	if(argc > 2)
	{
		ifstream file;
		file.open(param[1]);

		ANTLRInputStream input(file);
		ExprLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		ExprParser parser(&tokens);
		tree::ParseTree* tree = parser.prog();

		Calc visitor;
		int resultat = (int)visitor.visit(tree);
		cout<<"Résultat "<<resultat<<endl;

		return 0;
	}
	else
	{
		cerr << "USAGE: " << argv[0] << "<FILENAME.c>" << endl;
		return 1; 
	}
}
