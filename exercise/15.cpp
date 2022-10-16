#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, i = 0;
    scanf("%d %d", &n, &m);
    vector<int>v(n, 0);
    while(i < n)
    {
        v[i] = i+1;
        i++;
    }
    auto it = v.begin();
    while(!v.empty())
    {
        int now = (m - 1) % v.size() + 1;
        for (int j = 1; j < now; j++)
        {
            ++it;
            if(it == v.end())
                it = v.begin();
        }
        printf("%d\n", *it);
        it = v.erase(it);
        if(it == v.end())
            it = v.begin();
    }
    return 0;
}