#include <iostream>
#include <fstream>
#include <string>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseVisitor.h"
#include "Visiteur.h"
#include "AsmWriter.h"

using namespace antlr4;
using namespace std;

const char BLEU [] = {033,'[','3','4','m'};
const char ROUGE [] = {033,'[','3','1','m'};
const char JAUNE [] = {033,'[','3','3','m'};
const char RESET [] = {033,'[','m',017};

#ifdef DEBUG
// ostream & debug ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en bleu.
ostream & debug (ostream & os){
    os.write(BLEU, sizeof(BLEU));
    return os;
}//----- Fin de debug
#endif

// ostream & erreur ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en rouge.
ostream & erreur (ostream & os){
	os.write(ROUGE, sizeof(ROUGE));
	return os;
}//----- Fin de erreur

// ostream & attention( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il écrive en jaune.
ostream & attention (ostream & os){
	os.write(JAUNE, sizeof(JAUNE));
	return os;
}//----- Fin de attention

// ostream & debug ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il reprenne ses
//      paramètres initiaux.
ostream & raz (ostream & os){
	os.write(RESET, sizeof(RESET));
	return os;
}//----- Fin de debug

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

		AsmWriter *a=new AsmWriter(argv[1],tree->toStringTree(&parser));
		a->convert();

		string outFile = "resultat.s";
		ofstream myfile (outFile);
		if (myfile.is_open()){
			myfile << ".text\n";
			myfile << ".global main\n";
			// TODO rajouter le body du code assembleur
			myfile << "main:\n";
			myfile << "movl\t$" << resultat << ", %eax\n";
			myfile << "ret";
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
