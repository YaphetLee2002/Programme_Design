#include<stdio.h>
#define TYPE long long
void InsertionSort(TYPE A[], int N)
{
    int j, P;
    int Tmp;
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}
int main()
{
    TYPE A[3], Worth, B[3];
    Worth = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf("%lld", &A[i]);
        B[i] = A[i];
    }
    InsertionSort(B, 3);
    for (int i = 0; i < 3; i++)
    {
        while(A[i] >= 3)
        {
            Worth += 5 * (A[i] / 3) * A[(i + 1) % 3] * A[(i + 2) % 3];
            A[i] %= 3;
        }
    }
    switch (A[0] * A[1] * A[2])
    {
    case 1:
        if(Worth) 
            Worth += 1;
        break;
    case 2: Worth += 3;
        break;
    case 4: Worth += 6;
        break;
    case 8: 
        if(B[1] > 2 && B[2] > 2)
        {
            Worth = (B[1]/3 - 1) * (B[2]/3) * B[0] * 3 * 5;
            Worth += (B[1]/3) * (B[2]/3 - 1) * B[0] * 3 * 5;
            Worth += B[0] * 8 * 5;
            Worth += 3 + 5 * (B[0] / 3);
        }
        else
            Worth += 12;
        break;
    default:
        break;
    }
    printf("%lldm\n", Worth);

    return 0;
}
