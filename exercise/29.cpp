#include <stdio.h>
int main()
{
    int t, m, n, x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d %d", &m, &n, &x, &y);
        if ((m - x) ^ (n - y) ^ (x - 1) ^ (y - 1))
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}