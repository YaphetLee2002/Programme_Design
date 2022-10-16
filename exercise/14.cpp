#include <bits/stdc++.h>
using namespace std;
struct city
{
    int nxt, to;
} City[200001];
int in[200001], number, n, m, x, y, head[200001], f[200001];
queue<int> Q;
void Store(int begin, int end) //邻接表存储；
{
    City[++number].nxt = head[begin];
    City[number].to = end;
    head[begin] = number;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        Store(x, y);
        in[y]++; //统计y的入度；
    }
    for (int i = 1; i <= n; i++) //检查所有初始入度为0的节点
    {
        if (!in[i]) //如果该点的入度为0说明该点是起点
        {
            Q.push(i); //该点入队
            f[i] = 1;  //入度为0，则结果为1
        }
    }
    while (!Q.empty())
    {
        int this_head = Q.front(); //取队首元素
        Q.pop();
        for (int i = head[this_head]; i != 0; i = City[i].nxt)
        {
            in[City[i].to]--;    //他能到的儿子节点的入度减1（相当于删除该点）
            if (!in[City[i].to]) //如果该点入度为0将他置为下一次的起点
            {
                f[City[i].to] = f[this_head] + 1;
                Q.push(City[i].to); //将该点入队；
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", f[i]);
    return 0;
}