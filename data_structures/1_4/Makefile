FILENAME = include

default:
	make bin
	make run

bin: $(FILENAME).c Makefile
	gcc -o $(FILENAME) $(FILENAME).c

run: $(FILENAME)
	./$(FILENAME)

debug:
	gcc -DDEBUG -g -o $(FILENAME) $(FILENAME).c
	gdb $(FILENAME)

.PHONY: clean

clean:
	rm $(FILENAME) *~ \.*~
