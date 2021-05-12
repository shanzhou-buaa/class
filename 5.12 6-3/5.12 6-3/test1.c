//#include <ctype.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct numop
//{ // define elemnet
//	int num;
//	char op;
//} sto[501];
//
//struct opstack
//{ // define stack
//	int top;
//	struct numop sto[500];
//};
//
//struct Tree
//{ // define Tree
//	int n;
//	char o;
//	struct Tree *l;
//	struct Tree *r;
//};
//
//struct tree_pro
//{ // tree stack
//	struct Tree tree[502];
//	int top;
//} t;
//
//typedef struct opstack stack;
//stack o;                // operation
//struct Tree *u, *v, *w; // temporary struct
//char c;
//int i, j, k, n;
//
//void initstack(stack *s)
//{ // init stack
//	s->top = -1;
//}
//
//void push_tree(struct tree_pro *t, int m,
//	char c)
//{ // stack in member and operation
//	if (m != -1)
//	{
//		t->tree[++t->top].l = NULL;
//		t->tree[t->top].r = NULL;
//		t->tree[t->top].n = m;
//		t->tree[t->top].o = 0;
//	}
//	else
//	{
//		u = (struct Tree *)malloc(sizeof(struct Tree));
//		v = (struct Tree *)malloc(sizeof(struct Tree));
//		w = (struct Tree *)malloc(sizeof(struct Tree));
//		memcpy(v, &t->tree[t->top--], sizeof(struct Tree));
//		memcpy(u, &t->tree[t->top], sizeof(struct Tree));
//		w->o = c;
//		switch (c)
//		{
//		case '+':
//			w->n = u->n + v->n;
//			break;
//		case '-':
//			w->n = u->n - v->n;
//			break;
//		case '*':
//			w->n = u->n * v->n;
//			break;
//		case '/':
//			w->n = u->n / v->n;
//			break;
//		}
//		w->l = (struct Tree *)&u;
//		w->r = (struct Tree *)&v;
//		memcpy(&t->tree[t->top], w, sizeof(struct Tree));
//	}
//}
//
//void pushstack_o(stack *o, struct tree_pro *t, int m,
//	char c)
//{ // stack in member and operation
//	if (m <= o->sto[o->top].num && o->sto[o->top].num != 3)
//	{
//		for (; o->sto[o->top].num != 3;)
//		{
//			if (m > o->sto[o->top].num)
//				break;
//			push_tree(t, -1, o->sto[o->top].op);
//			o->top--;
//			if (o->top == -1)
//				break;
//		}
//	}
//	if (m == 4)
//	{ // right round
//		for (; o->sto[o->top].num != 3; o->top--)
//		{
//			push_tree(t, -1, o->sto[o->top].op);
//		}
//		o->top--;
//	}
//	else
//	{
//		o->sto[++o->top].num = m; // save number and operation
//		o->sto[o->top].op = c;
//	}
//}
//
//void print_tree(struct tree_pro *t)
//{
//	if (t->tree[t->top].o != 0)
//		printf("%c ", t->tree[t->top].o);
//	else
//		printf("%d ", t->tree[t->top].n);
//	if (u->o != 0)
//		printf("%c ", u->o);
//	else
//		printf("%d ", u->n);
//	if (v->o != 0)
//		printf("%c \n", v->o);
//	else
//		printf("%d \n", v->n);
//	printf("%d", t->tree[t->top].n);
//}
//
//int main()
//{
//	initstack(&o); // init all, num, operation
//	t.top = -1;
//	while ((c = getchar()) != '=')
//	{
//		if (c >= '0' && c <= '9')
//		{
//			for (i = 0; c >= '0' && c <= '9'; c = getchar()) // number produce
//				n = c - '0' + n * 10;
//			ungetc(c, stdin);
//			push_tree(&t, n, 0); // stack in
//			n = 0;
//		}
//		else if (c != ' ')
//		{
//			switch (c)
//			{ // distribute number
//			case '+':
//				pushstack_o(&o, &t, 1, c);
//				break;
//			case '-':
//				pushstack_o(&o, &t, 1, c);
//				break;
//			case '*':
//				pushstack_o(&o, &t, 2, c);
//				break;
//			case '/':
//				pushstack_o(&o, &t, 2, c);
//				break;
//			case '(':
//				pushstack_o(&o, &t, 3, c);
//				break;
//			case ')':
//				pushstack_o(&o, &t, 4, c);
//				break;
//			}
//		}
//	}
//	for (; o.top != -1; o.top--)
//	{
//		push_tree(&t, -1, o.sto[o.top].op);
//	}
//	print_tree(&t);
//	return 0;
//}