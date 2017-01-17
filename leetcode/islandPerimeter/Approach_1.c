#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int p = 0;
    for(int row = 0; row < gridRowSize; row++) {
        for(int col = 0; col < gridColSize; col++) {
            if(grid[row][col] == 1) {
                /* 贴边的肯定有一个边 */
                if(row == 0) {
                    p++;
                }
                if(row == gridRowSize - 1) {
                    p++;
                }
                if(col == 0) {
                    p++;
                }
                if(col == gridColSize - 1) {
                    p++;
                }
                /* 挨着0的肯定会有一个边 */
                if((row-1 >= 0) && grid[row-1][col] == 0) {
                    p++;
                }
                if((row+1 < gridRowSize) && (grid[row+1][col] == 0)) {
                    p++;
                }
                if((col-1 >= 0) && grid[row][col-1] == 0) {
                    p++;
                }
                if((col+1 < gridColSize) && (grid[row][col+1] == 0)) {
                    p++;
                }
            }
        }
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
