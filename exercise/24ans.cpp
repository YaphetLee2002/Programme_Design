#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#define INF 999999
using namespace std;
class Edge
{
public:
    int fr, to, cap, cost;
    Edge(int f, int t, int ca, int co)
    {
        fr = f;
        to = t;
        cap = ca;
        cost = co;
    }
};
vector<int> g[1020];
vector<Edge> e;
int n, m, ans, S = 0, T = 1010, p[1020], dis[1020], caArray[1020], vArray[1020];
void AddEdge(int co, int f, int t, int ca)
{
    e.push_back(Edge(f, t, ca, co));
    e.push_back(Edge(t, f, 0, -co));
    int tmp = e.size();
    g[f].push_back(tmp - 2), g[t].push_back(tmp - 1);
    return;
}
int spfa()
{
    memset(dis, 42, sizeof(dis));
    p[T] = -1;
    p[S] = -1;
    queue<int> q;
    q.push(S);
    caArray[S] = INF;
    dis[S] = 0;
    vArray[S] = true;
    while (!q.empty())
    {
        int x = q.front(), l = g[x].size();
        q.pop();
        vArray[x] = false;
        for (int i = 0; i < l; i++)
        {
            int ti = g[x][i], to = e[ti].to;
            Edge &ee = e[ti];
            if (ee.cap > 0 && dis[to] > dis[x] + ee.cost)
            {
                dis[to] = dis[x] + ee.cost;
                p[to] = ti;
                caArray[to] = min(ee.cap, caArray[x]);
                if (!vArray[to])
                    vArray[to] = true, q.push(to);
            }
        }
    }
    if (p[T] == -1)
        return 0;
    ans += caArray[T] * dis[T];
    for (int i = p[T]; i != -1; i = p[e[i].fr])
    {
        e[i].cap -= caArray[T];
        e[i ^ 1].cap += caArray[T];
    }
    return 1;
}

int main()
{
    int t = 0, s = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        t = s;
        scanf("%d", &s);
        t = s - t;
        if (t == 0){}
        else if (t > 0)
            AddEdge(0, S, i, t);
        else
            AddEdge(0, i, T, t * (-1));
        AddEdge(0, i + 1, i, INF);
    }
    AddEdge(0, n + 1, T, s);
    int c, l, r;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &l, &r, &c);
        AddEdge(c, l, r + 1, INF);
    }
    while (spfa());
    printf("%d\n", ans);
    return 0;
}