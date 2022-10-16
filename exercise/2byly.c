#include <stdio.h>
int main()
{
    long long int a, b, c,Worth = 0;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    if (a == 1 && b == 1 && c == 1)
        Worth = 0;
    else if (a % 3 == 0 || b % 3 == 0 || c % 3 == 0)
        Worth = b * c * a / 3 * 5;
    else if (a % 3 == 1 && b % 3 == 1 && c % 3 == 1)
        Worth = (b * a * c - 1) / 3 * 5 + 1;
    else if ((a % 3 == 1 && b % 3 == 1 && c % 3 == 2) || (a % 3 == 1 && b % 3 == 2 && c % 3 == 1) || (a % 3 == 2 && b % 3 == 1 && c % 3 == 1))
        Worth = (b * a * c - 2) / 3 * 5 + 3;
    else if ((a % 3 == 1 && b % 3 == 2 && c % 3 == 2) || (a % 3 == 2 && b % 3 == 1 && c % 3 == 2) || (a % 3 == 2 && b % 3 == 2 && c % 3 == 1))
        Worth = (b * a * c - 4) / 3 * 5 + 6;
    else if ((a % 3 == 2 && b % 3 == 2 && c % 3 == 2) && ((a >= 2 && c >= 5 && b >= 5) || (b >= 2 && c >= 5 && a >= 5) || (c >= 2 && a >= 5 && b >= 5)))
        Worth = (b * a * c - 8) / 3 * 5 + 13;
    else if ((a % 3 == 2 && b % 3 == 2 && c % 3 == 2) && ((2 == a && c >= 2 && b >= 2) || (2 == b && c >= 2 && a >= 2) || (2 == c && a >= 2 && b >= 2)))
        Worth = (b * a * c - 8) / 3 * 5 + 12;
    printf("%lld\n", Worth);
}