# POUR IF : ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
#           ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP
ANTLR=/shares/public/tp/antlr4/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/antlr4
OPTIONS=

EXEC     = exec
CXX       = clang++

CXXFLAGS   = -g -std=c++11 -I
LDFLAGS  =

SRC      = $(wildcard *.cpp)
OBJ      = $(SRC:.cpp=.o)

all: antlr $(EXEC)

antlr:
	@echo --------- Génération des classes pour l'analyse avec antlr ----------------
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp Expr.g4

$(EXEC):
	@echo --------- Compilation des sources du projet avec les classes d'antlr --------------
	$(CXX) $(CXXFLAGS) $(ANTLRRUNTIME)/antlr4-runtime/ -o $(EXEC) *.cpp $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

.PHONY: clean mrproper

depend:
	@echo --------- Génération des dépendances dans le makefile --------------
	makedepend $(SRC)

clean:
	@echo --------- Suppression des classes compilées --------------
	@rm -rf *.o

mrproper: clean
	@echo --------- Suppression de l'exécutable --------------
	@rm -rf $(EXEC) core
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
