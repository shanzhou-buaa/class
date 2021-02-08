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

//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];//存放一个人的信息
	int size;//记录当前已有的元素个数
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
//初始化通讯录
void InitContact(struct Contact* ps);

//添加
void AddContact(struct Contact* ps);

//删除
void DelContact(struct Contact* ps);

//查找
void SearchContact(const struct Contact* ps);

//打印内容
void ShowContact(const struct Contact* ps);

//修改
void ModifyContact(struct Contact* ps);