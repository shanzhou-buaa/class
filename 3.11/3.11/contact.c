#include "contact.h"


void initContact(struct Contact* pc)
{
	pc->sz = 0;
	memset(pc->a, 0, sizeof(pc->a));
}
void addContact(struct Contact* pc)
{
	if (pc->sz == MAX)
		printf("full\n");
	printf("name:");
	scanf("%s", pc->a[pc->sz].name);

	printf("age:");
	scanf("%d", &(pc->a[pc->sz].age));

	printf("tel:");
	scanf("%s", pc->a[pc->sz].tel);

	pc->sz++;
	printf("add success\n\n");
}

int FindByName(const struct Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->a[i].name, name) == 0)
			return i;
	}
	return -1;
}

void delContact(struct Contact* pc)
{
	if (pc->sz == 0)
		printf("empty\n\n");
	else
	{
		printf("name:");
		char name[NAME_MAX];
		scanf("%s", name);
		int pos = FindByName(pc, name);
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->a[i] = pc->a[i + 1];
		}
		pc->sz--;
		printf("del success\n\n");
	}
}

void showContact(const struct Contact* pc)
{
	printf("%-15s%-5s%-20s\n", "name", "age", "telephone");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s%-5d%-20s\n", pc->a[i].name, pc->a[i].age, pc->a[i].tel);
	}
	printf("\n");
}

void searchContact(const struct Contact* pc)
{
	printf("name\n");
	char name[NAME_MAX];
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("no\n");
	else
	{
		printf("%-15s%-5s%-20s\n", "name", "age", "telephone");
		printf("%-15s%-5d%-20s\n", pc->a[pos].name, pc->a[pos].age, pc->a[pos].tel);
	}
}

void modifyContact(struct Contact* pc)
{
	printf("name\n");
	char name[NAME_MAX];
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("no\n");
	else
	{
		printf("name:");
		scanf("%s", pc->a[pos].name);

		printf("age:");
		scanf("%d", &(pc->a[pos].age));

		printf("tel:");
		scanf("%s", pc->a[pos].tel);

		printf("modify success\n\n");
	}
}