#include<stdio.h>
const int maxn = 200005;
int n;
int a[maxn];
void findminandmax(int n); // you should finish this
int cmp(int i, int j)
{
	if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n)
		return -2;
	if (a[i] > a[j])
		return 1;
	if (a[i] == a[j])
		return 0;
	if (a[i] < a[j])
		return -1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	findminandmax(n);
	return 0;
}

void findminandmax(int n)
{
	int Max[maxn] = {0};
	int Min[maxn] = {0};
	int max = 1, min = 1;
	for (int i = 1; i <= n; i++)
	{
		if (cmp(2 * i, 2 * i - 1) > 0)
		{
			Max[i-1] = 2 * i;
			Min[i-1] = 2 * i - 1;
		}
		else
		{
			Max[i-1] = 2 * i - 1;
			Min[i-1] = 2 * i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if(cmp(Max[i], max) > 0)
			max = Max[i];
		if(cmp(min, Min[i]) > 0)
			min = Min[i];
	}
	printf("%d %d\n", min, max);
}
