#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void Run(int num)
{
    vector<int> b(0, 0);
    int isBegin = 1;
    while (num)
    {
        b.push_back(num & 1U);
        num >>= 1;
    }
    for (auto i = b.size() - 1; i > 0; i--)
    {
        if (b[i] != 0 || i == 1)
        {
            if (isBegin)
                isBegin = 0;
            else
            {
                if(b[0] || b[1] || b[i])
                    putchar('+');
            }
            if (i == 1)
            {
                if (b[1] && b[0])
                    printf("2+2(0)");
                else if (b[1] && !b[0])
                    putchar('2');
                else if (!b[1] && b[0])
                    printf("2(0)");
            }
            else
            {
                printf("2(");
                Run(i);
                putchar(')');
            }
        }
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    Run(num);
    putchar('\n');
    return 0;
}