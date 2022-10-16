#include<cstdio>
#include <algorithm>
#define MAX 1000010
struct point
{
    long x, y;
} p[1000010];
int a[1000010];
inline int CompareX(const point a, const point b)
{
    return a.x < b.x;
}
inline int CompareY(int a, int b)
{
    return p[a].y < p[b].y;
}
inline long Min(long a, long b)
{
    return a < b ? a : b;
}
inline long Distance(const point &a, const point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long RunProgramme(int low, int high)
{
    if (low == high)
        return MAX;
    if (low + 1 == high)
        return Distance(p[low], p[high]);
    int mid = (low + high) >> 1;
    long ans = Min(RunProgramme(low, mid), RunProgramme(mid + 1, high));
    int i, j, c = 0;
    for (i = low; i <= high; ++i)
    {
        if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
            a[c++] = i;
    }
    std::sort(a, a + c, CompareY);
    for (i = 0; i < c; ++i)
    {
        int k = i + 7 > c ? c : i + 7;
        for (j = i + 1; j < k; ++j)
        {
            if (p[a[j]].y - p[a[i]].y > ans)
                break;
            ans = Min(Distance(p[a[i]], p[a[j]]), ans);
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    long minDistance;
    for (int i = 0; i < n; ++i)
        scanf("%ld %ld", &p[i].x, &p[i].y);
    std::sort(p, p + n, CompareX);
    minDistance = RunProgramme(0, n - 1);
    printf("%ld\n", minDistance);
    return 0;
}