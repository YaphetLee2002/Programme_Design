#include<stdio.h>
#include<string.h>
typedef char ElementType;

int main(void)
{
    ElementType string_old[1001][101], prefix[101];
    int times;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) //读入每一组字符串
        scanf("%s", string_old[i]);

    scanf("%s", prefix);

    int prefix_length = strlen(prefix);
    int new_counts = 0;
    ElementType string_new[1001][101];

    for (int i = 0; i < times; i++)
    {
        if(strncmp(string_old[i], prefix, prefix_length) == 0)
            strcpy(string_new[new_counts++], string_old[i]);
    }
    times = new_counts;
    
    if(!new_counts)
    {
        printf("No Result!\n");
        return 0;
    }

    //希尔排序部分
    int i, j, Increment;
    ElementType Tmp[101];
    for (Increment = times / 2; Increment > 0; Increment /= 2)
    {
        for (i = Increment; i < times; i++)
        {
            strcpy(Tmp, string_new[i]);
            for (j = i; j >= Increment; j -= Increment)
            {
                if (strcmp(Tmp, string_new[j - Increment]) < 0)
                    strcpy(string_new[j], string_new[j - Increment]);
                else
                    break;
            }
            strcpy(string_new[j], Tmp);
        }
    }

    for (int k = 0; k < times; k++)
        printf("%s\n", string_new[k]);
    return 0;
}