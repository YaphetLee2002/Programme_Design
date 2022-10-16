#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
void Print(vector<int>v)
{
    for (auto &&i : v)
        cout << i << " ";
    cout << endl;
}
int main()
{
    int timeCount, workerTypeCount;
    scanf("%d %d", &timeCount, &workerTypeCount);
    vector<int>everyPeriodNeedPeople(timeCount, 0);
    for (auto &&i : everyPeriodNeedPeople)
        scanf("%d", &i);
    vector<int>beginTime(workerTypeCount, 0);
    vector<int>endTime(workerTypeCount, 0);
    vector<int>cost(workerTypeCount, 0);
    for (int i = 0; i < workerTypeCount; i++)
        scanf("%d %d %d", &beginTime[i], &endTime[i], &cost[i]);
    
    return 0;
}