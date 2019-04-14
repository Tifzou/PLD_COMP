/*************************************************************************
                           PLD_COMP  -  description
      Compilateur pour le language définit dans le polycopié.
      Ce dernier renvoie la structure en mémoire généré lors de l'analyse du fichier.

      Les différentes options sont :
      -a pour afficher les erreurs détectées à l'analyse
      -c <NomOptionel> pour générer un fichier ASM avec la possibilité de définir le nom de ce dernier
      -o pour activer l'optimisation du code analysé

      L'ajout, lors de la compilation du projet, des définitions suivantes modifie le programme :
      - GEN_EXE permet d'obtenir un executable à la fin de l'exécution (extension en .exe)
      - DEBUG permet d'afficher certaines informations de débuggage.

                             -------------------
    début                : 05/03/2019
    copyright            : (C) 2019 par HALUNKA Matthieu, COQUIO-LEBRESNE Clémentine,
                            FLOCH Tifenn, GASIUK Anatolii, HIRT Christophe, PAUGOIS Alan
    e-mail               : matthieu.halunka@insa-lyon.fr (chef de projet)
*************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

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

// void afficheStruct(Cell *block, typeBlock type, int compteur)
// Algorithme :
//      Affiche les blocks des structures if-else
void afficheStruct(Cell *block, typeBlock type, int compteur)
{
    if(block== nullptr)
    {
        return;
    }
    if(block->data.back().type==commandeType::CONDITION)
    {
        cout<<"BlockCondition"<<endl;
    }
    else
    {
        cout<<"BlockSimple"<<endl;
    }
    if(type==typeBlock::IF_BLOCK)
    {
        cout<<"IF"+to_string(compteur)<<endl;
    }
    else
    {
        cout<<"ELSE"+to_string(compteur)<<endl;
    }
    for(Commande cmd: block->data)
    {
        cout<<cmd.type<<" ";
        for(string st: cmd.elements)
        {
            cout<<st<<" ";
        }
        cout<<endl;
    }
    afficheStruct(block->suivant1, typeBlock::IF_BLOCK, ++compteur);
    afficheStruct(block->suivant2, typeBlock::ELSE_BLOCK, ++compteur);
}//----- Fin de afficheStruct
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

// ostream & raz ( ostream & os )
// Algorithme :
//      Change les paramètres du ostream pour qu'il reprenne ses
//      paramètres initiaux.
ostream & raz (ostream & os){
    os.write(RESET, sizeof(RESET));
    return os;
}//----- Fin de raz

//-------------------------------------------- Constructeurs - destructeur

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        cerr << erreur << "USAGE: " << argv[0] << " <FILENAME.c> -c <OUTPUTNAME> -a -o" << endl << raz;
        return -1;
    }

    string inputName=argv[1];
    string outputName=argv[1];

    size_t foundCpp=outputName.find(".cpp",0);
    if (foundCpp!=std::string::npos){
        outputName.replace(outputName.end()-4,outputName.end(),"");
    }else{
        size_t foundC=outputName.find(".c",0);
        if (foundC!=std::string::npos){
            outputName.replace(outputName.end()-2,outputName.end(),"");
        }else{
            cerr<<erreur<<"USAGE: Le fichier d'entrée n'a pas la bonne extension !"<<endl<<raz;
            return -1;
        }
    }

    //Lecture des options
    bool toAsmFile=false;   //-c avec possibilité de nom en sortie
    bool custumOutput=false;
    bool showError=false;   //-a pour afficher les erreurs d'analyse
    if(argc > 2){
        if(strcmp(argv[2], "-c") == 0){
            toAsmFile=true;
            if(argc > 3){
                if(strcmp(argv[2], "-a") != 0){
                    outputName = argv[3];
                    custumOutput=true;
                }else {
                    showError=true;
                }
            }
        }else if(strcmp(argv[2], "-a") == 0) {
            showError = true;
            if (argc > 3 && strcmp(argv[3], "-c") == 0){
                toAsmFile=true;
                if (argc > 4) {
                    outputName = argv[4];
                    custumOutput=true;
                }
            }
        }else if(strcmp(argv[2], "-o") != 0) {
            cerr<<attention<<"USAGE: Seules -a -o et -c sont des options reconnues par le programme"<<endl<<raz;
        }

    }

    ifstream file;
    file.open(inputName);
    ANTLRInputStream input(file);

    ExprLexer lexer(&input);
    if(lexer.getNumberOfSyntaxErrors() > 0) {
        cerr << "Le lexer a rencontrée des erreurs !" << endl;
        return -1;
    }
    CommonTokenStream tokens(&lexer);
    file.close();

    ExprParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();


    cout << tree->toStringTree(&parser) << endl;

    if(showError){
        cerr<<erreur;
        //cerr<<tree->getNumberOfSyntaxErrors()<<" erreurs ont été detectées lors de l'analyse via la grammaire !"<<endl;
    }

    if(parser.getNumberOfSyntaxErrors() > 0) {
        if(showError){
            cerr << "Le parseur a rencontrée des erreurs !" << raz<<endl;
        }
        return -1;
    }

    Visiteur visitor(showError);
    //vector<vector<string>> resultat = visitor.visit(tree);
    if(!visitor.visit(tree)||visitor.checkError()){
        if(showError){
            cerr<<"Des erreurs sont apparues lors de l'analyse statique !"<<raz<<endl;
        }
        return -1;
    }
    Symbole resultat=visitor.getSymboleManager();
    if(showError){
        cerr<<raz<<endl;
    }

    ListC *stack = resultat.getFlowControl();

#ifdef DEBUG
    Cell * curCell = stack->first;
    cout<<debug;
    afficheStruct(curCell, typeBlock::IF_BLOCK, 0);

    /*for (Commande curCommande: curCell->data) {
        cout << curCommande.type << " : ";
        for (string s : curCommande.elements) {
            cout << s << " ";
        }
        cout << endl;
    }

        cout<<"block IF"<<endl;
    for (Commande curCommande: curCell->suivant1->data) {
        cout << curCommande.type << " : ";
        for (string s : curCommande.elements) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout<<"block ELSE"<<endl;
    for (Commande curCommande: curCell->suivant2->data) {
        cout << curCommande.type << " : ";
        for (string s : curCommande.elements) {
            cout << s << " ";
        }
        cout << endl;
    }

    cout<<"block FIN"<<endl;
    for (Commande curCommande: curCell->suivant1->suivant1->data) {
        cout << curCommande.type << " : ";
        for (string s : curCommande.elements) {
            cout << s << " ";
        }
        cout << endl;
    }*/
    cout<<raz;
#endif

    if(toAsmFile){
        AsmWriter* a = new AsmWriter((!custumOutput)?(outputName+".s"):outputName, tree->toStringTree(&parser));
        a->writeOutputFile(stack->first, stack->last);
    }

#ifdef GEN_EXE
    if(!toAsmFile){
        AsmWriter* a = new AsmWriter(outputName+".s", tree->toStringTree(&parser));
        a->writeOutputFile(stack->first);

        string asCmd = "as -o " + outputName+".o " + outputName+".s";
        system(asCmd.c_str());

        string gccCmd = "gcc " + outputName +".o -o " + outputName+".exe";
        system(gccCmd.c_str());


        string rmCmd = "rm " + outputName +".o " + outputName+".s";
        system(rmCmd.c_str());
    }else{

        string asCmd = "as -o " + outputName+".o "+outputName;
        if(!custumOutput){
            asCmd=asCmd+".s";
        }
        system(asCmd.c_str());

        string gccCmd = "gcc " + outputName +".o -o " + outputName+".exe";
        system(gccCmd.c_str());

        string rmCmd = "rm " + outputName +".o";
        system(rmCmd.c_str());
    }
#endif

    return 0;

}