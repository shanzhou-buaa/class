#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int tree[900005][26];
int times[900005];
typedef struct sentences
{
	int begin;
	int end;
	int times;
}sentences;
sentences sen[150000];
int comp(const void* a, const void* b)
{
	return ((*(sentences*)b).times - (*(sentences*)a).times);
}
char all[7000005];
int pos = 0;
int main()
{
	FILE* read = fopen("article.txt", "r");
	FILE* write = fopen("results.txt", "w");
	FILE* stop = fopen("stopwords.txt", "r");
	int sum, p = 0, n = 0;
	scanf("%d", &sum);
	char c = 0;
	while (1)
	{
		c = fgetc(stop);
		if (c == EOF)
			break;
		else if (c == '\n')
			continue;
		else
		{
			p = 0, n = 0;
			while (c != '\n' && c != EOF && c != '\r')
			{
				n = (tolower(c)) - 'a';
				if (tree[p][n] == 0)
				{
					pos++;
					tree[p][n] = pos;
				}
				p = tree[p][n];
				c = fgetc(stop);
			}
			times[p] = -1;
		}
	}
	int i = 0, j = 0, index = 0, line = 0, x = 0;
	int article_len = fread(all, 1, 7000000, read);
	for (index = 0; index < article_len; index++)
	{
		if (all[index] != '?' && all[index] != '.' && all[index] != '!')//句子分割标志
		{
			if (j == 0)
			{
				sen[line].begin = index;
				j = 1;
			}
			if (isalpha(all[index]))
			{
				p = 0;
				while (isalpha(all[index]))
				{
					n = tolower(all[index]) - 'a';
					if (tree[p][n] == 0)
					{
						pos++;
						tree[p][n] = pos;
					}
					p = tree[p][n];
					index++;
				}
				index--;
				if (times[p] != -1)
					times[p]++;
			}
			else
				continue;
		}
		else
		{
			sen[line].end = index;
			index++;
			line++;
			j = 0;
		}
	}
	for (j = sen[i].begin; i < line; j++)
	{
		if (j == sen[i].end)
		{
			i++;
			continue;
		}
		if (isalpha(all[j]))
		{
			p = 0, x = 0;
			while (isalpha(all[j]))
			{
				n = tolower(all[j]) - 'a';
				if (tree[p][n] == 0)
				{
					x = 0;
					break;
				}
				p = tree[p][n];
				j++;
				x = times[p];
			}
			while (isalpha(all[j]))
				j++;
			if (x != -1)
				sen[i].times += x;
			j--;
		}
	}
	qsort(sen, line, sizeof(sen[0]), comp);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", sen[i].times);
		while (all[sen[i].begin] == ' ')
			sen[i].begin++;
		for (j = sen[i].begin; j <= sen[i].end; j++)
			fputc(all[j], stdout);
		fputc('\n', stdout);
	}
	for (i = 0; i < sum; i++)
	{
		fprintf(write, "%d ", sen[i].times);
		while (all[sen[i].begin] == ' ')
			sen[i].begin++;
		for (j = sen[i].begin; j <= sen[i].end; j++)
			fputc(all[j], write);
		fputc('\n', write);
	}

	fclose(stop);
	fclose(read);
	fclose(write);
	return 0;
}