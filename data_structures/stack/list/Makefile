SOURCE = stack.c
OBJECT = stack.o
PROGRAM = stack

obj: $(SOURCE)
	gcc -c $(SOURCE)

bin: $(OBJECT)
	gcc -o $(PROGRAM) $(OBJECT)

.PHONY: clean

clean:
	-rm -f $(PROGRAM) $(OBJECT) *~ \.*~
