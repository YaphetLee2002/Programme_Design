#include <stdio.h>
#include <stdlib.h>
typedef long long SB;

SB array[1000010] = {0};
SB new_array[1000010] = {0};
void Swap(SB *a, SB *b)
{
    SB c = *a;
    *a = *b;
    *b = c;
}
SB Partition(SB low, SB high)
{
    SB key = new_array[low];
    SB i = low, j = high + 1;
    do
    {
        while (new_array[++i] < key);
        while (new_array[--j] > key);
        Swap(&new_array[i], &new_array[j]);
    }while(i < j);
    Swap(&new_array[i], &new_array[j]);
    Swap(&new_array[low], &new_array[j]);
    return j;
}
void GetNum(SB k, SB l, SB r)
{
    if (l < r)
    {
        SB s = Partition(l, r);
        if (s > k)
            GetNum(k, l, s - 1);
        if (s < k)
            GetNum(k, s + 1, r);
    }
}
int main(void)
{
    SB n = 0, i = 0, h = 0;
    int act;
    int check;
    SB p = 0, x = 0;
    SB L = 0, R = 0, k = 0;
    scanf("%lld", &n);
    while(i != n)
        scanf("%lld", &array[++i]);
    scanf("%lld", &act);
    {
        for (i = 1; i <= act; i++)
        {
            scanf("%d", &check);
            {
                if (check == 1)
                {
                    scanf("%lld %lld", &p, &x);
                    array[p + 1] = x;
                }
                else
                {
                    scanf("%lld %lld %lld", &L, &R, &k);
                    for (h = 1; h <= R - L + 1; h++)
                        new_array[h] = array[L + h];
                    GetNum(k, 1, h - 1);
                    printf("%lld\n", new_array[k]);
                }
            }
        }
    }
    return 0;
}