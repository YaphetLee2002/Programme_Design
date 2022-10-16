#include <iostream>
using namespace std;
const int maxn = 1005;
int n;
bool good[maxn][maxn];
void guessdalao(int n); // you should finish this
int better(int a, int b)
{
	if (a <= 0 || a > n || b <= 0 || b > n)
		return -1;
	return good[a][b];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int t;
			scanf("%d", &t);
			good[i][j] = t;
		}
	guessdalao(n);
	return 0;
}
#include<vector>
void guessdalao(int n)
{

	vector<int> a(n, 0);
	vector<int> b(n, 0); 
	int k = 0, p = n, q = n, flag = 1;
	int t, at;
	while(n)
	{
		--n;
		a[n] = n + 1;
	}
	while (1)
	{
		k = 0;
		for (int i = 1; i < q; i += 2, k++)
		{
			t = better(a[i - 1], a[i]);
			if (t == 1)
				b[k] = a[i - 1];
			if (t == 0)
				b[k] = a[i];

		}
		if (q % 2)
		{
			b[k] = a[q - 1];
			k = k + 1;
		}
		q = k;
		for (int i = 0; i < q; i++)
			a[i] = b[i];
		if (q == 1)
			break;
	}
	for (int i = 1; (i - 1 < p) && flag; i++)
	{
		if (!(a[0] - i))
			continue;
		t = better(a[0], i);
		at = better(i, a[0]);
		if ((t != 1) || (at != 0))
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		printf("%d\n", a[0]);
	else
		puts("-1");
}