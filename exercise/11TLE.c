#include<stdio.h>

long int
Pow(long int X, unsigned int N)
{
    if(N == 0)
        return 1;
    if(N == 1)
        return X;
    if(!(N / 2))
        return Pow(X * X, N / 2);
    else
        return Pow(X * X, N / 2) * X;
}

int main(void)
{
    long int leftbound, rightbound, all_daffodil_number[100];
    int number_counts = 0;
    scanf("%ld %ld", &leftbound, &rightbound);
    for (int i = leftbound; i <= rightbound; i++)
    {
        long int original_number = i;
        long int daffodil_number = 0;
        int digit = 0;
        while(original_number)
        {
            original_number /= 10;
            digit++;
        }
        original_number = i;
        while(original_number)
        {
            daffodil_number += Pow(original_number % 10, digit);
            original_number /= 10;
        }
        if(daffodil_number == i)
        {
            all_daffodil_number[number_counts] = i;
            number_counts++;
        }
    }
    printf("%d\n", number_counts);
    for (int i = 0; i < number_counts; i++)
        printf("%ld\n",all_daffodil_number[i]);
    
    return 0;
}