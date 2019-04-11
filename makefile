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
	@echo --------- Génération avec antlr ----------------
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp Expr.g4

$(EXEC):
	@echo --------- Compilation des sources --------------
	$(CXX) $(CXXFLAGS) $(ANTLRRUNTIME)/antlr4-runtime/ -o $(EXEC) *.cpp $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

.PHONY: clean mrproper

depend:
	makedepend $(SRC)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC) core
# DO NOT DELETE

main.o: ExprLexer.h ExprParser.h ExprBaseVisitor.h ExprVisitor.h Visiteur.h
ExprVisitor.o: ExprVisitor.h ExprParser.h
ExprParser.o: ExprVisitor.h ExprParser.h
ExprLexer.o: ExprLexer.h
ExprBaseVisitor.o: ExprBaseVisitor.h ExprVisitor.h ExprParser.h
