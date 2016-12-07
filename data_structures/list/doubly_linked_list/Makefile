SOURCE = list.c print_list.c test.c exchange.c
OBJ    = list.o print_list.o test.o exchange.o
BIN    = test

.PHONY: all clean

all:
	make obj
	make bin
	make run

debug: $(SOURCE)
	gcc -g -c $(SOURCE)
	gcc -g -o $(BIN) $(OBJ)

obj: $(SOURCE)
	gcc -c $(SOURCE)

bin: $(OBJ)
	gcc -o $(BIN) $(OBJ)

run: $(BIN)
	./$(BIN)

clean:
	-rm -f *~ \.*~ $(OBJ) $(BIN)
