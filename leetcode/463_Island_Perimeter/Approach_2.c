#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int count = 0;
    int repeat = 0;
    for(int row = 0; row < gridRowSize; row++) {
        for(int col = 0; col < gridColSize; col++) {
            if(grid[row][col] == 1) {
                count++;

                if(row != 0 && grid[row-1][col] == 1) repeat++;
                if(col != 0 && grid[row][col-1] == 1) repeat++;
            }
        }
    }

    return 4 * count - 2 * repeat;
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
