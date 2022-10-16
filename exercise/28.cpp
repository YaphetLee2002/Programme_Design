#include<stdio.h>
const double pai = 3.1415926;   
int main(void)
{
    double m, n;
    scanf("%lf %lf", &n, &m);
    int t1 = 2 * m / pai;
    double t = (double)t1;
    double ans = 0;
    
    ans += n * m * (1 + n);
    for (double i = 1; i <= n; i++)
    {
        ans += 2 * m * (n * n + i * i + n);
        ans += 2 * n * m * (m - 1) * (2 * i + n + 1);
        ans -= 4 * m * t * (2 * i * n + i - i * i);
        ans += t * (t + 1) * i * (2 * n - i + 1) * pai;
    }
    ans /= (double)2;
    if(m == 1)
        for (int i = 1; i <= n; i++)
            ans -= 2 * i;
    printf("%lf\n", ans);
}