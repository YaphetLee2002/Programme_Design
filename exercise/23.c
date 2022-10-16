#include<stdio.h>
#include<math.h>
#define MAX 100005
typedef long long ElementType;

int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(void)
{
    ElementType X[MAX];
    ElementType Y[MAX];
    int point_count;
    ElementType target_x, target_y;
    scanf("%d", &point_count);
    for (int i = 0; i < point_count; i++)
        scanf("%ld %ld", &X[i], &Y[i]);
    if(point_count == 1)
    {
        printf("0\n");
        return 0;
    }
    qsort(X, point_count, sizeof(ElementType), cmp);
    qsort(Y, point_count, sizeof(ElementType), cmp);
    target_x = X[point_count / 2];
    target_y = Y[point_count / 2];

    ElementType ans = 0;
    for(int i = 0; i < point_count; i++)
    {
        ans += abs(X[i] - target_x);
        ans += abs(Y[i] - target_y);
    }
    printf("%ld\n", ans);
}