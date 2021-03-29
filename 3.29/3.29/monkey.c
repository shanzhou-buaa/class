#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode
{
	int data;
	struct listnode* next;
}ln;

void josephu(int n, int k, int m)
{
	ln* head = NULL;
	ln* p = NULL;
	ln* r = NULL;

	int i = 0;
	for (i = 1; i <= n; i++)
	{
		r = (ln*)malloc(sizeof(ln));
		r->data = i;
		if (head == NULL)
		{
			head = r;
			p = r;
		}
		else
		{
			p->next = r;
			p = p->next;
		}
	}
	p->next = head;
	r = p;
	p = head;
	for (i = 0; i < k - 1; i++)
	{
		r = p;
		p = p->next;
	}
	while (p->next != p)
	{
		for (i = 0; i < m - 1; i++)
		{
			r = p;
			p = p->next;
		}
		r->next = p->next;
		free(p);
		p = r->next;
	}
	printf("%d\n", p->data);
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	josephu(n, k, m);
	return 0;
}