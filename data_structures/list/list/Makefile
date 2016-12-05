SOURCE = list.c print_list.c test.c
OBJ    = list.o print_list.o test.o
BIN    = test

.PHONY: all clean

all:
	make bin

debug: $(SOURCE)
	gcc -g -c $(SOURCE)
	gcc -g -o $(BIN) $(OBJ)

obj: $(SOURCE)
	gcc -c $(SOURCE)

bin: $(OBJ)
	gcc -o $(BIN) $(OBJ)

clean:
	-rm -f *~ \.*~ $(OBJ) $(BIN)
