CC=gcc
CFLAGS=-I. -Wall
CUNIT=-lcunit

OBJ=main.o bf.o
TEST_OBJ=test_bf.o bf.o

BIN=brainfuck
TEST_BIN=test_bf

all: $(BIN) $(TEST_BIN)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(TEST_BIN): $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CUNIT)

clean :
	-rm  *.o $(BIN) $(TEST_BIN)