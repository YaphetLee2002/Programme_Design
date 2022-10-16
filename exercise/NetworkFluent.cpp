#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void update_residual_network(int u, int flow)
{
    while (pre[u] != -1)
    {
        map[pre[u]][u] -= flow;
        map[u][pre[u]] += flow;
        u = pre[u];
    }
}
int find_path_bfs(int s, int t)
{
    memset(visited, 0, sizeof(visited));
    memset(pre, -1, sizeof(pre));
    visited[s] = 1;
    int min = INF;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == t)
            break;

        for (int i = 1; i <= m; i++)
        {
            if (visited[i] == 0 && map[cur][i] != 0)
            {
                q.push(i);
                min = (min < map[cur][i] ? min : map[cur][i]);
                pre[i] = cur;
                visited[i] = 1;
            }
        }
    }
    if (pre[t] == -1)
        return 0;

    return min;
}
int edmonds_karp(int s, int t)
{
    int new_flow = 0;
    int max_flow = 0;
    do
    {
        new_flow = find_path_bfs(s, t);
        update_residual_network(t, new_flow);
        max_flow += new_flow;
    } while (new_flow != 0);
    return max_flow;
}