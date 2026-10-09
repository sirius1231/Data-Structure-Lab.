SRC  = $(wildcard *.cpp)
OBJ  = $(SRC:.cpp=.o)
EXEC = run
CC   = g++
FLAG = -std=c++11 -g -Wall

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(FLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
