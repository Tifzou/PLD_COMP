EXEC     = exec
CC       = g++

CFLAGS   = 
LDFLAGS  = 

SRC      = $(wildcard *.cpp)
OBJ      = $(SRC:.cpp=.o)

all: $(EXEC)

${EXEC}: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
