#include <stdio.h>
#include <stdlib.h>
#include <err.h>

typedef struct _cell {
    int row;
    int col;
} cell;

struct _land {
    cell* c;
    int total;
};

typedef (struct _land)* land;

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int p = 0; /* Perimeter */
    land l;

    l = malloc(sizeof(struct _land));
    if(l == NULL) err(-1, "malloc: l: out of space!");

    l->total = 0;
    l->c = malloc(gridRowSize * gridColSize * sizeof(struct _cell));
    if(l->c == NULL) err(-1, "malloc: l->c: out of space!");

    for(int row = 0; row < gridRowSize; row++) {
        for(int col = 0; col < gridColSize; col++) {
            if(grid[row][col] == 1) {
                l->c[0].row = row;
                l->c[0].col = col;
                l->total++;
                break;
            }
        }
    }

    for(int row = l->c[0].row, int col = l->c[0].col;
            row < gridRowSize, col < gridColSize;) {

    }

    return p;
}

int main()
{
    int row = 4;
    int col = 4;

    int a[] = {0, 1, 0, 0};
    int b[] = {1, 1, 1, 0};
    int c[] = {0, 1, 0, 0};
    int d[] = {1, 1, 0, 0};

    int** grid = malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++) {
        grid[i] = malloc(col * sizeof(int));
    }

    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    grid[3] = d;

    printf("%d\n", islandPerimeter(grid, row, col));

    return 0;
}
