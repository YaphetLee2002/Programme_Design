#include <cstdio>
#include <cstring>

char chars[13][11];
int lengt[13][13];
int used[13] = {0};
int n, ans;

void RunProgramme(int last, int length)
{
	int i;
	if (length > ans)
		ans = length;
	for (i = 1; i <= n; i++)
	{
		if ((lengt[last][i] > 0) && (used[i] < 2))
		{
			used[i]++;
			RunProgramme(i, length + lengt[last][i]);
			used[i]--;
		}
	}
}

int main()
{
	int i;
	char ch;
	scanf("%d", &n);
	getchar();
	for (i = 1; i <= n; i++)
		scanf("%s\n", chars[i]);
	scanf("%c", &ch);
	char s1[25], s2[25];
	int tmp1, tmp2, k, z, min_length;
	int flag;
	for (tmp1 = 1; tmp1 <= n; tmp1++)
	{
		for (tmp2 = 1; tmp2 <= n; tmp2++)
		{
            int strl1 = strlen(chars[tmp1]);
            int strl2 = strlen(chars[tmp2]);
			if (strl1 < strl2)
				min_length = strl1;
			else
				min_length = strl2;
			k = 1;
			flag = 1;
			lengt[tmp1][tmp2] = 0;
			while (k < min_length && flag)
			{
				for (z = strl1 - k; z <= strl1; z++)
					s1[z - strl1 + k] = chars[tmp1][z];
				for (z = 0; z < k; z++)
					s2[z] = chars[tmp2][z];
				s2[k] = '\0';
				if (strcmp(s1, s2) == 0)
				{
					lengt[tmp1][tmp2] = strlen(chars[tmp2]) - k;
					flag = 0;
				}
				k++;
			}
		}
	}
	ans = 0;
	for (i = 1; i <= n; i++)
	{
		if (chars[i][0] == ch)
		{
			used[i] = 1;
			RunProgramme(i, strlen(chars[i]));
			used[i] = 0;
		}
	}
	printf("%d\n", ans);
}