ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4 # a changer pour chaque ordi /!\
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP # a changer pour chaque ordi /!\
EXEC     = exec
CC       = g++

CFLAGS   = 
LDFLAGS  = 

SRC      = $(wildcard *.cpp)
OBJ      = $(SRC:.cpp=.o)

all: antlr

antlr : 
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp Expr.g4
	clang++ -g -std=c++11 -I $(ANTLRRUNTIME)/antlr4-runtime/ -o exe *.cpp $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

${EXEC}: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

	
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
