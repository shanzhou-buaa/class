#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct student
{
	int id;
	char name[15];
	int en;//机器
	char time[20];//时间
}student;

int main()
{
	student stu[205];
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%s%d%s", &stu[i].id, stu[i].name, &stu[i].en, stu[i].time);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (stu[j].id > stu[j + 1].id)
			{
				student temp;
				memcpy(&temp, &stu[j], sizeof(student));
				memcpy(&stu[j], &stu[j + 1], sizeof(student));
				memcpy(&stu[j + 1], &temp, sizeof(student));
			}
		}
	}
	student ans[205];
	int num = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			//id一样，en不一样
			if (stu[i].id == stu[j].id && stu[i].en != stu[j].en)
			{
				memcpy(&ans[num++], &stu[i], sizeof(student));
			}
		}
	}
	for (i = 0; i < num - 1; i++)
	{
		if (strcmp(ans[i].name, ans[i + 1].name) == 0)
			ans[i].id = 0;
	}
	for (i = 0; i < num; i++)
	{
		if (ans[i].id != 0)
			printf("%d %s\n", ans[i].id, ans[i].name);
	}
	return 0;
}