#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char string[100];
    scanf("%s", string);
    if(string[0] == 'F')
        string[2] = toupper(string[2]);
    int i = 2;
    while(string[i])
    {
        if(string[i] == '_')
            string[i + 1] = toupper(string[i + 1]);
        i++;
    }
    i = 2;
    while(string[i])
    {
        if(string[i] == '_')
        {
            i++;
            continue;
        }
        putchar(string[i++]);
    }
    putchar('\n');
    return 0;
}