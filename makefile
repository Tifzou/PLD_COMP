ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP
OPTIONS=

EXEC     = exec
CXX       = clang++

CXXFLAGS   = -g -std=c++11 -I
LDFLAGS  = 

SRC      = $(wildcard *.cpp)
OBJ      = $(SRC:.cpp=.o)

all: exec

antlr : 
	@echo ---- Compilation des sources avec antlr --------
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp Expr.g4
	$(CXX) $(CXXFLAGS) $(ANTLRRUNTIME)/antlr4-runtime/ -o exe *.cpp $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
	

exec:
	@echo --------- Compilation des sources --------------
	$(CXX) $(CXXFLAGS) $(ANTLRRUNTIME)/antlr4-runtime/ -o exe *.cpp $(ANTLRRUNTIME)/lib/libantlr4-runtime.a


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
