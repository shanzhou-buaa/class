#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ���˵���Ϣ
	int size;//��¼��ǰ���е�Ԫ�ظ���
};

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);

//���
void AddContact(struct Contact* ps);

//ɾ��
void DelContact(struct Contact* ps);

//����
void SearchContact(const struct Contact* ps);

//��ӡ����
void ShowContact(const struct Contact* ps);

//�޸�
void ModifyContact(struct Contact* ps);