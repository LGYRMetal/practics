BIN = Approach_1 Approach_2 Approach_3 Approach_4 Approach_5

1_Approach: Approach_1.c
	gcc Approach_1.c -o Approach_1

2_Approach: Approach_2.c
	gcc Approach_2.c -o Approach_2

3_Approach: Approach_3.c
	gcc Approach_3.c -o Approach_3

4_Approach: Approach_4.c
	gcc Approach_4.c -o Approach_4

5_Approach: Approach_5.c
	gcc Approach_5.c -o Approach_5

debug1_Approach: Approach_1.c
	gcc -g Approach_1.c -o Approach_1

debug2_Approach: Approach_2.c
	gcc -g Approach_2.c -o Approach_2

debug3_Approach: Approach_3.c
	gcc -g Approach_3.c -o Approach_3

debug4_Approach: Approach_4.c
	gcc -g Approach_4.c -o Approach_4

debug5_Approach: Approach_5.c
	gcc -g Approach_5.c -o Approach_5
	
.PHONY: clean

clean:
	-rm -rf *.o *~ \.*~ *.out $(BIN)
	-rm -rf __pycache__
