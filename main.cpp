#include <iostream>
#include <fstream>
#include <string>

#include "antlr4-runtime/antlr4-runtime.h"
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
		file.close();

		ExprParser parser(&tokens);
		tree::ParseTree *tree = parser.prog();

		cout << tree->toStringTree(&parser) << endl;

		Visiteur visitor;
		int resultat = (int)visitor.visit(tree);
		cout << "Résultat " << resultat << endl;
		
		string outFile = "resultat.s";
		ofstream myfile (outFile);
		if (myfile.is_open()){
			myfile << ".text\n";
			myfile << ".global main\n";
			// TODO rajouter le body du code assembleur
			myfile << "main:\n";
			myfile << "\tmovl\t$" << resultat << ", %eax\n";
			myfile << "\tret";
			myfile.close();
		}else{
			cerr << "Unable to create .s file !"<< endl;
		}
		/*size_t foundCpp=outFile.find(".cpp",0);
		if (foundCpp!=std::string::npos){
			outFile.replace(outFile.end()-4,outFile.end(),".asm");
			cout<<"Okay, .cpp rules"<<endl;
		}else{
			size_t foundC=outFile.find(".c",0);
			if (foundC!=std::string::npos){
				cout<<"Okay, .c rules"<<endl;
				outFile.replace(outFile.end()-2,outFile.end(),".s");
			}else{
				cerr<<"Le fichier d'entrée n'a pas la bonne extension !\n";
				return -1;
			}
		}
*/

		return 0;
	}
	else
	{
		cerr << "USAGE: " << argv[0] << "<FILENAME.c>" << endl;
		return -1;
	}
}
