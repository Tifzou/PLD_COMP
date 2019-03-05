EXEC     = exec
CC       = g++

CFLAGS   = 
LDFLAGS  = 

SRC      = $(wildcard *.cpp)
OBJ      = $(SRC:.cpp=.o)

all: antlr $(EXEC)

antlr : 
	antlr4 -visitor -no-listener -Dlanguage=Cpp Expr.g4
	clang++ -g -std=c++11 \
		-I $ANTLRRUNTIMEDIR/antlr-runtime \
		-o exe *.cpp \
		$ANTLRRUNTIMEDIR/lib/libantlr4-runtime.a

${EXEC}: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
