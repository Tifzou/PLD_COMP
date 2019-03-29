#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
        ANTLRInputStream input(file);
        ExprLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        file.close();

        ExprParser parser(&tokens);
        tree::ParseTree *tree = parser.prog();

        cout << tree->toStringTree(&parser) << endl;

        Visiteur visitor;

        //vector<vector<string>> resultat = visitor.visit(tree);
        Symbole resultat = visitor.visit(tree);

        matrice *stack = resultat.getStack();

        for(Commande curCommande: *stack)
        {
            cout<<curCommande.type<<" : ";
            for(string s : curCommande.elements)
            {
                cout<<s<<" ";
            }
            cout<<endl;
        }

        AsmWriter *a = new AsmWriter(argv[1], "resultat.s", tree->toStringTree(&parser));
        a->convert();
        a->writeOutputFile(*stack);

        return 0;
    }
    else
    {
        cerr << "USAGE: " << argv[0] << "<FILENAME.c>" << endl;
        return -1;
    }
}