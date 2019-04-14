#Définition des variables
OPTIONS=
# Pour l'utiliser, écrire $ make OPTIONS="..." dans un shell
# -DDEBUG pour passer l'application en mode debug
# -DGEN_EXE pour générer un executable à la fin de la compilation par l'application


# POUR IF : ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
#           ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP
ANTLR=/shares/public/tp/antlr4/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/antlr4

CXX       = clang++
#Définition des options de compilation
CXXFLAGS   = -g -std=c++11 -I
LDFLAGS  =

#Définition des fichiers sources
SRC      = $(wildcard *.cpp)
#Définition des fichiers à compiler en .o
OBJ      = $(SRC:.cpp=.o)

CD          = cd
CLEAN       = mrproper
REP_TEST    = ./test/
EXEC_TEST   = ./mktest.sh

#Définition du nom de l'éxécutable à créer
EXEC        = exec

#Création de l'éxécutable et des classes de antlr
all: antlr $(EXEC)

antlr:
	@echo "--------- Génération des classes pour l'analyse avec antlr ----------------"
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp Expr.g4

$(EXEC):
	@echo "--------- Compilation des sources du projet avec les classes d'antlr --------------"
	$(CXX) $(CXXFLAGS) $(ANTLRRUNTIME)/antlr4-runtime/ -o $(EXEC) *.cpp $(ANTLRRUNTIME)/lib/libantlr4-runtime.a $(OPTIONS)

#La fonction de nettoyage n'est pas associé aux fichiers
.PHONY: $(CLEAN)

#Fonction de suppression de l'ensemble des fichiers crées par le makefile
$(CLEAN):
	@echo "--------- Suppression de l'exécutable et des classes compilées --------------"
	@rm -f $@ $(EXEC) $(OBJ) core

.PHONY: test
test:
	@$(MAKE) $(CLEAN)
	@$(MAKE)
	@echo "--------- Lancement du script de test : --------------\n"
	@($(CD) $(REP_TEST) && bash $(EXEC_TEST) )

depend:
	@echo "--------- Génération des dépendances dans le makefile --------------"
	makedepend $(SRC)

# DO NOT DELETE

ExprVisitor.o: ExprVisitor.h ExprParser.h
ExprBaseVisitor.o: ExprBaseVisitor.h ExprVisitor.h ExprParser.h
Symbole.o: Symbole.h
ExprLexer.o: ExprLexer.h
AsmWriter.o: AsmWriter.h /usr/include/stdio.h Symbole.h
Visiteur.o: Visiteur.h ExprBaseVisitor.h ExprVisitor.h ExprParser.h Symbole.h
main.o: ExprLexer.h ExprParser.h ExprBaseVisitor.h ExprVisitor.h Visiteur.h
main.o: Symbole.h AsmWriter.h /usr/include/stdio.h
ExprParser.o: ExprVisitor.h ExprParser.h
