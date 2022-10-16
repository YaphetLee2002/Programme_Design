#include <stdio.h>
#include<math.h>

typedef float Point;

float
CalulateDistance(Point A[], Point B[])
{
    float delta_x = A[0] - B[0];
    float delta_y = A[1] - B[1];
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int main(void)
{
    int point_number;
    float max = 0.0;
    float min = 9999.99;
    scanf("%d", &point_number); //输入点的总数
    Point point[10001][2];

    for (int i = 0; i < point_number; i++)
    {
        scanf("%f %f", &point[i][0], &point[i][1]); //输入每一个点的横纵坐标
        for (int j = 0; j < i; j++)
        {
            float current_distance = CalulateDistance(point[j], point[i]);
            max = max < current_distance ? current_distance : max;
            min = min > current_distance ? current_distance : min;
        }
    }
    printf("%.2f %.2f\n", min, max);
    return 0;
}