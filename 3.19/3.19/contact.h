#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 20
#define TEL_MAX 14
#define MAX 1000
#define DEFAULT_CAP 4

struct Info
{
	char name[NAME_MAX];
	int age;
	char tel[TEL_MAX];
};

struct Contact
{
	struct Info *a;
	int capacity;
	int sz;
};

void initContact(struct Contact* pc);

void addContact(struct Contact* pc);

void delContact(struct Contact* pc);

void showContact(const struct Contact* pc);

void searchContact(const struct Contact* pc);

void modifyContact(struct Contact* pc);

void DestroyContact(struct Contact* pc);
