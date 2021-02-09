#include "contact.h"


//找人
//找到返回下标，找不到返回-1
static int FindName(const struct Contact* ps, char name[MAX_NAME])
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


void CheckCapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr == NULL)
		{
			printf("增容失败\n");
		}
		else
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
	}
}



void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SIZE;
}


void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);
	printf("请输入名字\n");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄\n");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话\n");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址\n");
	scanf("%s", ps->data[ps->size].addr);
	printf("添加成功\n");
	ps->size++;
}


void DelContact(struct Contact* ps)
{
	printf("请输入要删除的名字\n");
	char name[MAX_NAME];
	scanf("%s", name);
	
	int pos, j;
	pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	printf("请输入要查找的名字\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = FindName(ps,name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", 
			"姓名", "年龄", "性别", "电话", "住址");
		printf("%-10s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}


void ModifyContact(struct Contact* ps)
{
	printf("请输入要修改的名字\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字\n");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄\n");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别\n");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话\n");
		scanf("%s", ps->data[pos].tele);
		printf("请输入住址\n");
		scanf("%s", ps->data[pos].addr);
		printf("修改完成\n");
	}
}


void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-5d\t%-5s\t%-12s\t%-20s\n", 
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex, 
				ps->data[i].tele,
				ps->data[i].addr);

		}
	}
}


void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}