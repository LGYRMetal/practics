BIN = Approch_1 Approch_2

Approch_1: Approch_1.c
	gcc Approch_1.c -o Approch_1

Approch_2: Approch_2.c
	gcc Approch_2.c -o Approch_2

debug_Approch_1: Approch_1.c
	gcc -g Approch_1.c -o Approch_1

debug_Approch_2: Approch_2.c
	gcc -g Approch_2.c -o Approch_2

.PHONY: clean

clean:
	-rm -rf *.o *~ \.*~ *.out $(BIN)
