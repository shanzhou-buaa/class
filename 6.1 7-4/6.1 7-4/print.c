#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int seq = 0;

typedef struct TreeNode
{
	int num;//���
	int type;//����
	int fatherNum;//���׵ı��
	int depth;//���
	int place;
	struct TreeNode* child[10];//����ָ��
	struct TreeNode* father;//����ָ��
}tn;
tn* root = NULL;

typedef tn* QNDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QNDataType val;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

typedef tn* STDataType;
typedef struct stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;//ջ������
}stack;

void StackInit(stack* st);

void StackDestroy(stack* st);

void StackPush(stack* st, STDataType x);

void StackPop(stack* st);

STDataType StackTop(stack* st);

//�շ���1���ǿշ���0
//int StackEmpty(stack* st);

bool StackEmpty(stack* st);

int StackSize(stack* st);

void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

void QueuePush(Queue* q, QNDataType x);

void QueuePop(Queue* q);

QNDataType QueueFront(Queue* q);

bool QueueEmpty(Queue* q);

tn* TreeNodeInsert(int id, int type, int fatherId, int port);
tn* TreeNodeCreate(int id, int type, int fatherId, int port, int depth, tn* pFather);
tn* FindFather(int fatherId);//�ҵ���Ӧ��ŵĸ����
tn* SameAncestor(tn* goal, tn* print);//Ѱ��Ŀ��������ĳһ����ӡ���Ĺ�������
//tn* PreOrder(tn* ans, tn* one, tn* another);//ǰ������ҵ����ȵĽ��
void PrevOrder(tn* root);

int main()
{
	int all, print;//�ܸ�������������
	scanf("%d%d", &all, &print);

	FILE* in = fopen("in.txt", "r");
	int i = 0;
	//�豸ID ���� ���ڵ�ID �˿ں�
	int id, type, fatherId, port;
	tn* goal = NULL;//Ŀ���ӡ����ָ��
	tn* PrintArray[300];//��ӡ������
	int PrintLen = 0;

	//�����н���������
	for (i = 0; i < all; i++)
	{
		fscanf(in, "%d%d%d%d", &id, &type, &fatherId, &port);
		if (id == print)
			goal = TreeNodeInsert(id, type, fatherId, port);//Ŀ���ӡ����ָ��
		else if (type == 2)
			PrintArray[PrintLen++] = TreeNodeInsert(id, type, fatherId, port);//�Ѵ�ӡ����������
		else
			TreeNodeInsert(id, type, fatherId, port);
	}

	PrevOrder(root);

	int distance = 99999999, index = 0;
	for (i = 0; i < PrintLen; i++)
	{
		tn* same = SameAncestor(goal, PrintArray[i]);
		int temp = goal->depth + PrintArray[i]->depth - 2 * same->depth;
		if (temp < distance)
		{
			distance = temp;
			index = i;
		}
		else if (temp == distance)
		{
			tn* one = PrintArray[index];//ԭ����������
			tn* another = PrintArray[i];//�µ�������
			
			if (another->place < one->place)
				index = i;
		}
	}

	//index���������������Ĵ�ӡ������ţ�root���������ĸ�
	//goal��Ŀ����������λ�ã�distance������Ĵ�ӡ����Ŀ����ľ���
	tn* ancestor = SameAncestor(goal, PrintArray[index]);
	printf("%d ", PrintArray[index]->num);
	tn* cur = goal;
	while (cur != ancestor)
	{
		if (cur->type == 0)
			printf("%d ", cur->num);
		cur = cur->father;
	}
	if (ancestor->type == 0)
		printf("%d ", ancestor->num);

	//��ջ����������
	cur = PrintArray[index];
	stack st;
	StackInit(&st);
	while (1)
	{
		if (cur->type == 0)
			StackPush(&st, cur);
		cur = cur->father;
		if (cur == ancestor)
			break;
	}
	while (!StackEmpty(&st))
	{
		tn* temp = StackTop(&st);
		StackPop(&st);
		printf("%d ", temp->num);
	}
	printf("\n");
	fclose(in);
	return 0;
}

//����һ���½��
tn* TreeNodeCreate(int id, int type, int fatherId, int port, int depth, tn* pFather)
{
	tn* temp = (tn*)malloc(sizeof(tn));
	temp->num = id;
	temp->type = type;
	temp->fatherNum = fatherId;
	temp->depth = depth;
	temp->father = pFather;

	int i = 0;
	for (i = 0; i < 8; i++)
		temp->child[i] = NULL;
	return temp;
}

tn* TreeNodeInsert(int id, int type, int fatherId, int port)
{
	//���ڵ�Ϊ��
	if (root == NULL)
	{
		root = TreeNodeCreate(id, type, fatherId, port, 1, NULL);
		return root;
	}
	else
	{
		tn* pFather = FindFather(fatherId);//�ҵ������
		tn* cur = TreeNodeCreate(id, type, fatherId, port, pFather->depth + 1, pFather);//�����½��
		pFather->child[port] = cur;//�����������
		return cur;
	}
}

//������ȱ��������������������ͬ˵���ҵ�
tn* FindFather(int fatherId)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);//���ڵ����
	while (!QueueEmpty(&q))//���в���ʱ
	{
		tn* temp = QueueFront(&q);//�õ���ͷ
		if (temp->num == fatherId)
			return temp;
		else
		{
			QueuePop(&q);
			int i = 0;
			for (i = 0; i < 8; i++)
			{
				//������Ӳ�Ϊ�գ����
				if (temp->child[i] != NULL)
					QueuePush(&q, temp->child[i]);
			}
		}
	}
	return NULL;
}

//Ѱ��Ŀ��������ĳһ����ӡ���Ĺ�������
tn* SameAncestor(tn* goal, tn* print)
{
	tn* cur = NULL;
	while (goal != root)
	{
		cur = print;
		while (cur != root)
		{
			if (goal == cur)
				return goal;
			cur = cur->father;
		}
		goal = goal->father;
	}
	if (goal == root && cur == root)
		return root;
	return NULL;
}


void PrevOrder(tn* anc)
{
	if (anc == NULL)
		return;
	anc->place = seq++;
	int i = 0;
	for (i = 0; i < 8; i++)
		PrevOrder(anc->child[i]);
}

//49 33
//0(4)-8(1)-16(1)-28(0)-31(5)-45,46
//ǰ������ҵ����ȵĽ��

//tn* PreOrder(tn* ans, tn* one, tn* another)
//{
//	if (ans == one)
//		return one;
//	if (ans == another)
//		return another;
//	int i = 0, j = 0;
//	int sign = 0;
//	for (i = 0; i < 8; i++)//���ĳһ�������һ�����ӵĺ���ȫΪ��
//	{
//		if (ans->child[i] == NULL)
//			continue;
//		sign = 0;
//		for (j = 0; j < 8; j++)
//		{
//			if (ans->child[i]->child[j] != NULL)
//				sign = 1;//�������������һ�����Ӳ�Ϊ��
//		}
//		if (sign == 1)
//			return PreOrder(ans->child[i], one, another);
//	}
//	
//	return NULL;
//}

void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
	free(pq);
}

void QueuePush(Queue* pq, QNDataType x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//û�н��
	//ֻ��һ�����
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	//������
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QNDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return (pq->head == NULL);
}


void StackInit(stack* st)
{
	assert(st);

	st->a = (STDataType*)malloc(sizeof(stack)* 4);
	st->top = 0;
	st->capacity = 4;
}

void StackDestroy(stack* st)
{
	assert(st);
	free(st->a);
	st->a = NULL;
	st->capacity = 0;
	st->top = 0;
}

void StackPush(stack* st, STDataType x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(st->a, sizeof(stack)* st->capacity * 2);

		if (tmp == NULL)
		{
			exit(-1);//������������
		}
		st->capacity *= 2;
		st->a = tmp;
	}
	st->a[st->top++] = x;
}

void StackPop(stack* st)
{
	assert(st);
	assert(!StackEmpty(st));

	st->top--;
}

STDataType StackTop(stack* st)
{
	assert(st);
	assert(!StackEmpty(st));

	return st->a[st->top - 1];
}

//�շ���true���ǿշ���false
bool StackEmpty(stack* st)
{
	assert(st);
	return (st->top == 0);
}

int StackSize(stack* st)
{
	assert(st);
	return st->top;
}