#include<iostream>
#include<stack>
using namespace std;
stack<int> Result;
int GetMod(int dividend, int divisor)
{
    if(dividend % divisor < 0)
        return dividend - (dividend / divisor + 1) * divisor;
    else
        return dividend % divisor;
}
int GetResult(int dividend, int divisor)
{
    int result = dividend / divisor;
    int mod = GetMod(dividend, divisor);
    result = (dividend % divisor < 0) ? result + 1 : result;
    Result.push(mod);
    return result;
}
int main()
{
    int dividend, divisor;
    scanf("%d %d", &dividend, &divisor);
    printf("%d=", dividend);
    while(dividend != 0)
        dividend = GetResult(dividend, divisor);
    while(!Result.empty())
    {
        printf("%d",Result.top());
        Result.pop();
    }
    printf("(base %d)", divisor);
    putchar('\n');
    return 0;
}