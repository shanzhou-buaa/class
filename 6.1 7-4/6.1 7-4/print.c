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
	int num;//编号
	int type;//类型
	int fatherNum;//父亲的编号
	int depth;//深度
	int place;
	struct TreeNode* child[10];//孩子指针
	struct TreeNode* father;//父亲指针
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
	int top;//栈顶
	int capacity;//栈的容量
}stack;

void StackInit(stack* st);

void StackDestroy(stack* st);

void StackPush(stack* st, STDataType x);

void StackPop(stack* st);

STDataType StackTop(stack* st);

//空返回1，非空返回0
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
tn* FindFather(int fatherId);//找到对应编号的父结点
tn* SameAncestor(tn* goal, tn* print);//寻找目标计算机和某一个打印机的公共祖先
//tn* PreOrder(tn* ans, tn* one, tn* another);//前序遍历找到优先的结点
void PrevOrder(tn* root);

int main()
{
	int all, print;//总个数，计算机编号
	scanf("%d%d", &all, &print);

	FILE* in = fopen("in.txt", "r");
	int i = 0;
	//设备ID 类型 父节点ID 端口号
	int id, type, fatherId, port;
	tn* goal = NULL;//目标打印机的指针
	tn* PrintArray[300];//打印机数组
	int PrintLen = 0;

	//把所有结点插入树中
	for (i = 0; i < all; i++)
	{
		fscanf(in, "%d%d%d%d", &id, &type, &fatherId, &port);
		if (id == print)
			goal = TreeNodeInsert(id, type, fatherId, port);//目标打印机的指针
		else if (type == 2)
			PrintArray[PrintLen++] = TreeNodeInsert(id, type, fatherId, port);//把打印机保存起来
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
			tn* one = PrintArray[index];//原来的最近结点
			tn* another = PrintArray[i];//新的最近结点
			
			if (another->place < one->place)
				index = i;
		}
	}

	//index是先序遍历的最近的打印机的序号，root是整个树的根
	//goal是目标计算机结点的位置，distance是最近的打印机和目标结点的距离
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

	//用栈倒着往上找
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

//创建一个新结点
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
	//根节点为空
	if (root == NULL)
	{
		root = TreeNodeCreate(id, type, fatherId, port, 1, NULL);
		return root;
	}
	else
	{
		tn* pFather = FindFather(fatherId);//找到父结点
		tn* cur = TreeNodeCreate(id, type, fatherId, port, pFather->depth + 1, pFather);//创建新结点
		pFather->child[port] = cur;//连接两个结点
		return cur;
	}
}

//广度优先遍历搜索整个树，编号相同说明找到
tn* FindFather(int fatherId)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);//根节点入队
	while (!QueueEmpty(&q))//队列不空时
	{
		tn* temp = QueueFront(&q);//拿到队头
		if (temp->num == fatherId)
			return temp;
		else
		{
			QueuePop(&q);
			int i = 0;
			for (i = 0; i < 8; i++)
			{
				//如果孩子不为空，入队
				if (temp->child[i] != NULL)
					QueuePush(&q, temp->child[i]);
			}
		}
	}
	return NULL;
}

//寻找目标计算机和某一个打印机的公共祖先
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
//前序遍历找到优先的结点

//tn* PreOrder(tn* ans, tn* one, tn* another)
//{
//	if (ans == one)
//		return one;
//	if (ans == another)
//		return another;
//	int i = 0, j = 0;
//	int sign = 0;
//	for (i = 0; i < 8; i++)//如果某一个结点有一个孩子的孩子全为空
//	{
//		if (ans->child[i] == NULL)
//			continue;
//		sign = 0;
//		for (j = 0; j < 8; j++)
//		{
//			if (ans->child[i]->child[j] != NULL)
//				sign = 1;//这个孩子至少有一个孩子不为空
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
	assert(!QueueEmpty(pq));//没有结点
	//只有一个结点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	//多个结点
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
			exit(-1);//结束整个程序
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

//空返回true，非空返回false
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