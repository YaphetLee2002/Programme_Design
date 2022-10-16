#include<iostream>
using namespace std;

int n, m, q, a[1000005];

int find(int x,int n);
int cmp(int i, int x)
{
    if(i > n|| i <= 0)
        return -2;
    if (a[i] > x)
        return 1;
    if (a[i] == x)
        return 0;
    return -1;
}

int main()
{
    scanf("%d %d", &n, &m); //读入

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]); //还是读入

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &q);
        int ans = find(q,n);  //看看查找的结果
        printf("%d ", ans); //输出
    }
    printf("\n");

    return 0;
}
int findx(int x, int l, int r)
{
    if (l > r)
        return -1;
    int half = (r + l) / 2;
    if(l == r)
    {
        if(cmp(l, x) == 0)
            return l;
        else if(cmp(r, x) == 0)
            return r;
        else
            return -1;
    }
    int flag = cmp(half, x);
    if(flag == 1)
        return findx(x, l, half - 1);
    if(flag == -1)
        return findx(x, half + 1, r);
    else
        return findx(x, l, half);
}
int find(int x,int n)
{
    return findx(x, 1, n);
}