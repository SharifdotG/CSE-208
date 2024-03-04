#include<stdio.h>
int max(int a, int b) {return a >= b ? a : b;}
int main()
{
    int i, j, n = 4, c = 8;           //Number of Product & Capacity 
    int V[] = {0, 1, 2, 4, 6};     //Values 
    int W[] = {0, 2, 3, 4, 5};      //Weights
    int array[n + 1][c + 1];
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            if(i == 0 || j == 0) array[i][j] = 0;
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= c; j++)
        {
            if(j < W[i])
            {
                array[i][j] = array[i - 1][j];
            }
            else
            {
                array[i][j] = max(array[i - 1][j], array[i - 1][j - W[i]] + V[i]);
            }
        }
    }
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            printf("%3d", array[i][j]);
        }
        puts("\n");
    }
    return 0;
}