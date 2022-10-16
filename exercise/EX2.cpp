
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution(int n, int m)
    {
        // write your code here
    }
    int doJudge(string usersAnswer, int lastAnswer)
    {
        // write your code here
    }
};

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> usersAnswers;
    vector<int> answers;
    for (int i = 0; i < m; i++)
    {
        char s[25555];
        int ans;
        scanf("%s%d", s, &ans);
        usersAnswers.push_back(s);
        answers.push_back(ans);
    }
    Solution yourSolution(n, m);
    for (int i = 0; i < m; i++)
    {
        int result = yourSolution.doJudge(usersAnswers[i], i == 0 ? -1 : answers[i - 1]);
        printf("%d\n", result);
    }
    return 0;
}