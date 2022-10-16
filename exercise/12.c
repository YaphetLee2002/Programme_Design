#include <stdio.h>
#include <string.h>

char chars[13][11];
int lengt[13][13];
int used[13] = {0};
int n, ans;

void make()
{
	char s1[25], s2[25];
	int i, j, k, z, min_length;
	int flag;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (strlen(chars[i]) < strlen(chars[j]))
				min_length = strlen(chars[i]);
			else
				min_length = strlen(chars[j]);
			k = 1;
			flag = 1;
			lengt[i][j] = 0;
			while (k < min_length && flag)
			{
				for (z = strlen(chars[i]) - k; z <= strlen(chars[i]); z++)
					s1[z - strlen(chars[i]) + k] = chars[i][z];
				for (z = 0; z < k; z++)
					s2[z] = chars[j][z];
				s2[k] = '\0';
				if (strcmp(s1, s2) == 0)
				{
					lengt[i][j] = strlen(chars[j]) - k;
					flag = 0;
				}
				k++;
			}
		}
	}
}

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
	for (i = 1; i <= n; i++) //读入所有单词
	{
		scanf("%s\n", chars[i]);
	}
	scanf("%c", &ch);
	make();
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