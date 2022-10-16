#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int totalNum, totalKind, nowKind = 0, ans;
    scanf("%d %d", &totalNum, &totalKind);
    ans = totalNum;
    queue<int> q;
    vector<int> isGet(totalKind + 1, 0);
    for (int i = 0; i < totalNum; i++){
        int tempKind;
        scanf("%d", &tempKind);
        q.push(tempKind);
        if(!isGet[tempKind])
            nowKind++ ;
        isGet[tempKind]++;
        if(nowKind == totalKind){
            while (isGet[q.front()] > 1){
                isGet[q.front()]--;
                q.pop();
            }
        }
        if(nowKind == totalKind && ans > (int)q.size())
            ans = q.size();
    }
    printf("%d\n", ans);
    return 0;
}