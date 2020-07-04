#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 9

int find_empty(int bo[][LEN], int *m, int *n);
int solve(int bo[][LEN]);
int valid(int bo[][LEN], int num, int row_val, int column_val);
void print_board(int bo[][LEN]);
int main(void)
{
    int board[][LEN] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}};
    clock_t t1, t2, t;
    printf("Initial Board :\n");
    print_board(board);
    t1 = clock();
    solve(board);
    t2 = clock();
    t = t2 - t1;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("_____________________________\n\n");
    printf("Result :\n");
    print_board(board);
    printf("\ntotal process time = %lf\n", time_taken);
    system("pause");
    return 0;
}

int find_empty(int bo[][LEN], int *m, int *n)
{
    int i, j = 0;
    for (i = 0; i < LEN; i++)
    {
        for (j = 0; j < LEN; j++)
        {
            if (bo[i][j] == 0)
            {
                *m = i;
                *n = j;
                return 1;
            }
        }
    }
    return -1;
}
int solve(int bo[][LEN])
{
    int m = 0, n = 0, i, res;
    int find = find_empty(bo, &m, &n);
    if (find == -1)
        return 1;
    for (i = 1; i < 10; i++)
    {
        res = valid(bo, i, m, n);
        if (res == 1)
        {
            bo[m][n] = i;

            if (solve(bo) == 1)
                return 1;

            bo[m][n] = 0;
        }
    }
    return -1;
}

int valid(int bo[][LEN], int num, int row_val, int column_val)
{
    int i, box_x, box_y, j;
    for (i = 0; i < LEN; i++)
    {
        if (bo[row_val][i] == num && column_val != i)
            return -1;
    }
    for (i = 0; i < LEN; i++)
    {
        if (bo[i][column_val] == num && row_val != i)
        {
            return -1;
        }
    }
    box_x = column_val / 3;
    box_y = row_val / 3;
    for (i = box_y * 3; i < (box_y * 3) + 3; i++)
    {
        for (j = box_x * 3; j < (box_x * 3) + 3; j++)
        {
            if (bo[i][j] == num && i != row_val && j != column_val)
                return -1;
        }
    }
    return 1;
}

void print_board(int bo[][LEN])
{
    int i, j;
    for (i = 0; i < LEN; i++)
    {
        if (i % 3 == 0 && i != 0)
            printf("- - - - - - - - - - - - - \n");
        for (j = 0; j < LEN; j++)
        {
            if (j % 3 == 0 && j != 0)
                printf(" | ");
            if (j == 8)
                printf("%d\n", bo[i][j]);
            else
                printf("%d ", bo[i][j]);
        }
    }
}
