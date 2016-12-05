SOURCE = queue.c
OBJ    = queue.o
BIN	   = queue

obj: $(SOURCE)
	gcc -c $(SOURCE)

bin: $(OBJ)
	gcc -o $(BIN) $(OBJ)

.PHONY: clean

clean:
	-rm -f *~ \.*~ $(OBJ) $(BIN)
