#include <stdio.h>
#include <stdlib.h>

int dfs(int** grid, int gridRowSize, int gridColSize, int row, int col)
{
    int p = 0;

    if(row < 0 || row > gridRowSize-1 ||
       col < 0 || col > gridColSize-1 ||
       grid[row][col] == -1) {
        return 0;
    }

    if(grid[row][col] == 0) {
        return 1;
    }
/*
    if(grid[row][col] == -1) {
        return 0;
    }
*/
    if(grid[row][col] == 1) {
        grid[row][col] = -1;

        if(row == 0) p++;
        if(col == 0) p++;
        if(row == gridRowSize-1) p++;
        if(col == gridColSize-1) p++;
    }

    return p + dfs(grid, gridRowSize, gridColSize, row-1, col) +
               dfs(grid, gridRowSize, gridColSize, row+1, col) +
               dfs(grid, gridRowSize, gridColSize, row, col-1) +
               dfs(grid, gridRowSize, gridColSize, row, col+1);
}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int row = 0;
    int col = 0;
/*
    for(row = 0; row < gridRowSize; row++) {
        for(col = 0; col < gridColSize; col++) {
            if(grid[row][col] == 1) {
                break;
            }
        }
        if(grid[row][col] == 1) {
            break;
        }
    }
*/
    for(row = 0; row < gridRowSize; row++) {
        for(col = 0; col < gridColSize; col++) {
            if(grid[row][col]) {
                return dfs(grid, gridRowSize, gridColSize, row, col);
            }
        }
    }

    return 0;
}

int main()
{
    int row = 1;
    int col = 1;

    int a[1][1] = {{1}};

    int** grid = malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++) {
        grid[i] = malloc(col * sizeof(int));
        grid[i] = a[i];
    }

    printf("%d\n", islandPerimeter(grid, row, col));

    return 0;
}

/*
int main()
{
    int row = 100;
    int col = 100;

    int a[100][100] = {
        {1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,1},
        {1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
        {1,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1},
        {0,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,1,1,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,1,1,0,0,0,0},
        {1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,1},
        {1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,0,1,1,1,0,0,0,1,0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,0,1,0,1},
        {1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,1,0,1},
        {0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,1,1,1,0,0,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,1},
        {0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1},
        {1,1,0,1,1,0,1,0,0,0,1,0,0,1,0,1,1,0,1,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,1,0,1,1,0,1},
        {1,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1},
        {1,1,1,0,0,0,1,0,1,1,0,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,1,1},
        {1,0,1,1,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,0,1,0},
        {1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1},
        {1,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,0,0,1,0,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,1},
        {0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1},
        {0,0,1,1,0,1,1,0,0,1,0,1,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,1},
        {1,0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,1,0,1,1},
        {1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0},
        {1,1,0,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,0,1,1,1},
        {0,1,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1},
        {0,0,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1},
        {0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,0,1},
        {1,1,0,0,1,1,1,1,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,1,1,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,1,0,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,1},
        {0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,1,1,0,1},
        {0,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,0,0,1,0,0,1,1,1},
        {0,1,0,1,1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,1,1,0,0,0,1},
        {1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,1,1,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,0,0,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1},
        {1,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,0,0},
        {1,0,1,1,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1},
        {1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1},
        {0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,1},
        {1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1},
        {0,1,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,1,0,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,0,1,1,1,0,1},
        {1,0,0,0,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,0,1},
        {1,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1,1,0,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1},
        {0,1,0,1,0,0,1,0,0,1,1,1,0,0,0,0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,1,0,1,0},
        {1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,0,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,0,1,1,1,0,0,0,1,0,1,1},
        {0,1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1},
        {0,0,1,0,1,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1},
        {1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,1,1,1,0,1,0},
        {1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1},
        {1,1,1,0,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0,1},
        {0,0,1,1,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1},
        {1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,1,0,1,0,1,0,1,0,0,1,0,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1},
        {1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1},
        {1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1},
        {0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1,1},
        {1,1,0,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1},
        {1,0,0,0,1,1,0,0,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,0,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0},
        {1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1},
        {1,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1},
        {0,1,0,1,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,1,1,1,0,1,0,1,1,0,0,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1},
        {1,1,0,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1},
        {1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1},
        {1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,0,0,0,0,0,0,1,0,1},
        {0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,1,1,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1},
        {0,0,1,0,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,0},
        {1,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1},
        {1,1,1,0,0,1,0,0,1,1,0,0,1,0,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0},
        {1,0,1,1,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,1,1},
        {1,0,0,0,0,0,1,1,1,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1},
        {1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1},
        {1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1},
        {1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1},
        {0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0},
        {1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,0,1,1,0,1,1,0},
        {0,0,1,0,1,0,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1},
        {0,1,1,0,1,0,0,1,1,0,1,0,1,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1},
        {1,1,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,0,1,0,1,1,1},
        {1,0,0,0,0,1,0,0,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,0,1,1,1,1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,1,0,0,0,1},
        {1,0,0,1,1,1,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,1,1,1},
        {1,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1},
        {0,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,1,1,0,1},
        {0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,0,0,1},
        {1,0,0,1,1,0,0,0,0,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,1,0,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,1,1,1,0,0,0,1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,1,1,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,0,0,1,0,0,1},
        {1,1,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1},
        {0,1,1,0,1,1,1,1,0,1,0,1,1,0,0,1,1,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,0,1,0,0,0},
        {0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,1,0},
        {1,1,1,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,1,0,0,1},
        {1,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1},
        {1,0,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,1,0},
        {1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1},
        {1,0,1,0,1,0,1,1,1,1,0,1,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0,0},
        {1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,0,0,1,1,0,1,0,0,0,1,1},
        {0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,1,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,0,1},
        {1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1},
        {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1},
        {1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,0,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,0,1,0},
        {1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,1,1},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,1,1,0,1,0,1,1,0,0,1,1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1},
        {1,1,1,0,1,1,1,1,1,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0}
    };

    int** grid = malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++) {
        grid[i] = malloc(col * sizeof(int));
        grid[i] = a[i];
    }

    printf("%d\n", islandPerimeter(grid, row, col));

    return 0;
}
*/