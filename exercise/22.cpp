#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k;
    double a[101][102];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + 1; j++)
            scanf("%lf", &a[i][j]);
    for (i = 1; i <= n; i++)
    {
        int k = i;
        for (j = i + 1; j <= n; j++)
            if (fabs(a[j][i]) > fabs(a[k][i]))
                k = j;
        if (fabs(a[k][i]) == 0)
        {
            puts("No Solution");
            return 0;
        }
        for (j = i; j <= n + 1; j++)
            swap(a[i][j], a[k][j]);
        double res = a[i][i];
        for (j = i; j <= n + 1; j++)
            a[i][j] /= res;
        for (k = 1; k <= n; k++)
        {
            if (k != i)
            {
                double res = a[k][i];
                for (j = i; j <= n + 1; j++)
                    a[k][j] -= res * a[i][j];
            }
        }
    }
    for (i = 1; i <= n; i++)
        printf("%0.2lf\n", a[i][n + 1]);
    return 0;
}