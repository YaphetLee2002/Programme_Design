#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
const int maxn = 200 + 5;
const int maxm = 2000 + 5;
int n, m, x, cnt = 0;
int head[maxn];
int dis[maxn];
struct node
{
    int e;
    int v;
    int nxt;
} edge[maxm << 1];
//**********************************function
inline int read()
{
    int ans = 0;
    char r = getchar();
    while (r < '0' || r > '9')
        r = getchar();
    while (r >= '0' && r <= '9')
    {
        ans = ans * 10 + r - '0';
        r = getchar();
    }
    return ans;
}

inline void addl(int u, int v, int w)
{
    edge[cnt].e = v;
    edge[cnt].v = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void datasetting()
{
    memset(head, -1, sizeof(head));
    n = read();
    m = read();
    x = read();
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        a = read();
        b = read();
        c = read();
        addl(a, b, c);
        addl(b, a, 0); //加边和反向边
    }
}

bool bfs() //bfs找深度
{
    memset(dis, -1, sizeof(dis)); //注意！不要忘了这句
    dis[1] = 0;                   //起点深度为0，从源向汇bfs
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        for (int i = head[r]; i != -1; i = edge[i].nxt)
        {
            int j = edge[i].e;
            if (dis[j] == -1 && edge[i].v) //如果这个点还没有被bfs且这条边的流量不为0
            {
                dis[j] = dis[r] + 1;
                q.push(j);
            }
        }
    }
    return dis[n] != -1; //若不可以到终点（起点）就返回false
}
int dfs(int u, int flo) //dfs就是求节点u及其子树在残量为flo时的最大增量
{
    if (u == n)
        return flo;  //如果是汇，直接返回flo
    int detla = flo; //用一个变量来保存flo，以方便更新其剩余残量
    for (int i = head[u]; i != -1; i = edge[i].nxt)
    {
        int v = edge[i].e;
        if (dis[v] == (dis[u] + 1) && (edge[i].v) > 0) //如果满足深度条件且边可以走
        {
            int d = dfs(v, min(detla, edge[i].v)); //向下递归
            //求v及其后续节点在残量为min(detla,edge[i].v)时的最大流量
            edge[i].v -= d;
            edge[i ^ 1].v += d; //边的处理
            //注意，编号为i的边的反向边的编号为i^1,这是根据存边时的cnt决定的
            detla -= d; //将本节点的剩余残量值更新
            if (detla == 0)
                break; //如果本节点已经没有残量可消耗了，就返回
        }
    }
    return flo - detla; //返回这个点已经被允许流过的流量
}
int dini() //求最大流量
{
    int ans = 0;
    while (bfs())
    {
        ans += dfs(1, INF); //用INF是因为我们不知道此时的残量到底是多少（其实这个问题还是值得想一下）
    }
    return ans;
}
//**********************************main
int main()
{
    freopen("datain.txt", "r", stdin);
    datasetting();
    int a = dini();
    if (a != 0)
        if (x % a)
            printf("%d %d", a, (x - (x % a)) / a + 1);
        else
            printf("%d %d", a, x / a);
    else
        printf("Orz Ni Jinan Saint Cow!");
    return 0;
}