CC=gcc
CFLAGS=-I. -Wall
CUNIT=-lcunit
COV=-coverage

BIN=brainfuck
TEST_BIN=test

all: $(BIN) $(TEST_BIN)

$(BIN):
	$(CC) -o $@ main.c bf.c $(CFLAGS)

$(TEST_BIN):
	$(CC) $(COV) -o $@ test_bf.c bf.c $(CFLAGS) $(CUNIT)

clean :
	-rm  *.o *.gcno *.gcda *.gcov $(BIN) $(TEST_BIN)