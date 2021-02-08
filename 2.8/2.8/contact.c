#include "contact.h"


//����
//�ҵ������±꣬�Ҳ�������-1
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


void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}


void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������\n");
		scanf("%s", ps->data[ps->size].name);
		printf("����������\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("������סַ\n");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}


void DelContact(struct Contact* ps)
{
	printf("������Ҫɾ��������\n");
	char name[MAX_NAME];
	scanf("%s", name);
	
	int pos, j;
	pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	printf("������Ҫ���ҵ�����\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = FindName(ps,name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", 
			"����", "����", "�Ա�", "�绰", "סַ");
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
	printf("������Ҫ�޸ĵ�����\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("����������\n");
		scanf("%s", ps->data[pos].name);
		printf("����������\n");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�\n");
		scanf("%s", ps->data[pos].sex);
		printf("������绰\n");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ\n");
		scanf("%s", ps->data[pos].addr);
		printf("�޸����\n");
	}
}


void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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