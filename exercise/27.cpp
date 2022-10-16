#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getVector(vector<int> &v)
{
    for (auto &&i : v)
        scanf("%d", &i);
}
int main()
{
    int a, b, times = 0;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(!a)
            break;
        times++;
        vector<int> tower1(a, 0);
        vector<int> tower2(b, 0);
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
        getVector(tower1);
        getVector(tower2);
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (tower1[i - 1] == tower2[j - 1])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i][j - 1], dp[i - 1][j]));
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        printf("Twin Towers #%d\n", times);
        printf("Number of Tiles : %d\n", dp[a][b]);
    }
    return 0;
}