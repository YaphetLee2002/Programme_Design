#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int RowIndex;
    scanf("%d", &RowIndex);
    int Num[100][100];
    for (int i = 0; i < RowIndex; i++)
    {
        Num[i][0] = Num[i][i] = 1;
        for (int space = 0; space < RowIndex - i - 1; space++)
            printf("     ");
        printf("%5d", Num[i][0]);
        for (int j = 1; j < i; j++)
        {
            Num[i][j] = Num[i - 1][j] + Num[i - 1][j - 1];
            printf("     ");
            printf("%5d", Num[i][j]);
        }
        if(i > 0)
        {
            printf("     ");
            printf("%5d", Num[i][i]);
        }
        putchar('\n');
    }  
    return 0;
}