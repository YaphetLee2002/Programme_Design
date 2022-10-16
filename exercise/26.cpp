#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
int comboCount = 0;
vector<int> preArray;
int isPreCombo(int n)
{
    if(n == 7)
    {
        return 1;
    }
    if(n < 9)
        return 0;
    int moreThanSeven = 0;
    string sequence = to_string(n);
    string newSequence(sequence.size() - 1, '0');
    for (size_t i = 0; i < sequence.size() - 1; i++)
    {
        newSequence[i] = abs(sequence[i + 1] - sequence[i]) + '0';
        if (newSequence[i] >= '7')
            moreThanSeven++;
    }
    if (!moreThanSeven)
        return 0;
    int nowNum = stoi(newSequence);
    return isPreCombo(nowNum);
}
void isCombo(int n)
{
    if(n <= 100000)
    {
        for (auto &&i : preArray)
        {
            if(n > i)
                continue;
            if(n == i)
                comboCount++;
            return ;
        }
    }
    int moreThanSeven = 0;
    string sequence = to_string(n);
    string newSequence(sequence.size() - 1, '0');
    for (size_t i = 0; i < sequence.size() - 1; i++)
    {
        newSequence[i] = abs(sequence[i + 1] - sequence[i]) + '0';
        if (newSequence[i] >= '7')
            moreThanSeven++;
    }
    if (!moreThanSeven)
        return ;
    int nowNum = stoi(newSequence);
    return isCombo(nowNum);
}
int main()
{
    int l, r;
    scanf("%d %d", &l, &r);
    for (int i = 1; i <= 100000; i++)
        if(isPreCombo(i))
            preArray.push_back(i);
    for (int i = l; i <= r; i++)
        isCombo(i);
    
    printf("%d\n", comboCount);
    return 0;
}