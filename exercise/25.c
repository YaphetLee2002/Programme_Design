#include <stdio.h>
const int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int count;
    scanf("%d", &count);
    while (count--){
        int m1, d1, m2, d2, x;
        scanf("%d %d %d %d %d", &m1, &d1, &m2, &d2, &x);
        for (int i = m2 - 1; i != m1; i--){
            if (!i){
                i = 13;
                continue;
            }
            x -= Month[i - 1];
        }
        x -= d2;
        x -= (Month[m1 - 1] - d1);
        if(m1 < m2 || (m1 == m2 && d1 < d2)){
            if(m1 > 2 || m2 <= 2)
                puts("?");
            else if(x)
                puts("R");
            else
                puts("P");
        }
        else{
            if(m1 > 2 && (m2 < 2 || (m2 == 2 && d2 <= 28)))
                puts("?");
            else if(x){
                if(m1 <= 2)
                    puts("R");
                else
                    puts("P");
            }
            else{
                if(m1 <= 2)
                    puts("P");
                else
                    puts("?");
            }
        }
    }
    return 0;
}