#include <stdio.h>

int GetMinPosition(const long long array[], long long n, long left, long right)
{
    long middle = (left + right) / 2;
    if (left + 1 == right)
    {
        if(n == array[left])
            return left;
        else
            return right;
    }
    else
    {
        if (left == right || n == array[middle])
            return middle;
        if (n < array[middle])
            return GetMinPosition(array, n, left, middle);
        if (n > array[middle])
            return GetMinPosition(array, n, middle, right);
    }
}

int GetMaxPosition(const long long array[], long long n, long left, long right)
{
    long middle = (left + right) / 2;
    if (left + 1 == right)
    {
        if(n == array[right])
            return right;
        else
            return left;
    }
    else
    {
        if (left == right || n == array[middle])
            return middle;
        if (n < array[middle])
            return GetMaxPosition(array, n, left, middle);
        if (n > array[middle])
            return GetMaxPosition(array, n, middle, right);
    }
}

int main(void)
{
    long long num[1000000];
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
        scanf("%lld", &num[i]);

    long left_border, right_border;
    scanf("%ld %ld", &left_border, &right_border);
    if (left_border > num[count - 1] || right_border < num[0] || left_border > right_border)
    {
        printf("No Result!\n");
        return 0;
    }
    long min, max;
    if (left_border > num[0])
    {
        min = GetMinPosition(num, left_border, 0, count);
        while(min && num[min-1] == num[min])
            min--;
    }
    else
        min = 0;
    if (right_border < num[count - 1])
    {
        max = GetMaxPosition(num, right_border, 0, count);
        while(max <= count && num[max+1] == num[max])
            max++;
    }
    else
        max = count - 1;
    for (int j = min; j <= max; j++)
    {
        printf("%lld\n", num[j]);
    }
    return 0;
}