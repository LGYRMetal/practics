#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int dfs(int** grid, int gridRowSize, int gridColSize, int row, int col)
{
    if(row == 0 || col == 0 ||
       row == gridRowSize-1 || col == gridRowSize-1 ||
       grid[row][col] == 0) {
        return 1;
    }
    else if(grid[row][col] == -1) {
        return 0;
    }
    else {
        grid[row][col] = -1;

        return dfs(grid, gridRowSize, gridColSize, row-1, col) +
               dfs(grid, gridRowSize, gridColSize, row+1, col) +
               dfs(grid, gridRowSize, gridColSize,  row, col-1) +
               dfs(grid, gridRowSize, gridColSize,  row, col+1);
    }
}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int i = 0;
    int j = 0;

    while(i < gridRowSize) {
        while(j < gridColSize) {
            if(grid[i][j] == 1)
                break;
        }
    }

    return dfs(grid, gridRowSize, gridColSize, i, j);
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
