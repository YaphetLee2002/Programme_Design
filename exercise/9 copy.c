#include<stdio.h>
#include<string.h>
typedef char ElementType;

int main(void)
{
    ElementType string_old[1000][100], prefix[100];
    int times;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) //读入每一组字符串
        scanf("%s", string_old[i]);

    scanf("%s", prefix);
    int prefix_length = strlen(prefix);

    //希尔排序部分
    int i, j, Increment;
    ElementType Tmp[100];
    for (Increment = times / 2; Increment > 0; Increment /= 2)
    {
        for (i = Increment; i < times; i++)
        {
            strcpy(Tmp, string_old[i]);
            for (j = i; j >= Increment; j -= Increment)
            {
                if (strcmp(Tmp, string_old[j - Increment]) < 0)
                    strcpy(string_old[j], string_old[j - Increment]);
                else
                    break;
            }
            strcpy(string_old[j], Tmp);
        }
    }
    for (int k = 0; k < times; k++)
    {
        if(strncmp(string_old[k], prefix, prefix_length) == 0)
            printf("%s\n", string_old[k]);
    }
    return 0;
}