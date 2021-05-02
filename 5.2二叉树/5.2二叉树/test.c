#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int BTData;

typedef struct BinaryTree
{
	BTData x;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;

#include "queue.h"

//根 左子树 右子树
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->x);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->x);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->x);
}

void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->x);
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);

		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}

	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q) != NULL)
			return false;
		else
			QueuePop(&q);
	}

	QueueDestroy(&q);
	return true;
}

//从第一层开始计数
int TreeKLevelSize(BTNode* root, BTData k)
{
	if (root == NULL)
		return 0;

	//root != NULL
	if (k == 1)
		return 1;

	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

//连续调用多次TreeSize时，size不清零，只有第一次的结果是对的
//用全局变量或静态变量不能解决

//多传一个参数psize，而且必须传指针
void TreeSize1(BTNode* root, int* psize)
{
	if (root == NULL)
		return;

	(*psize)++;
	TreeSize1(root->left, psize);
	TreeSize1(root->right, psize);
}

int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : (TreeSize2(root->left) + TreeSize2(root->right) + 1);
}

int LeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return LeafSize(root->left) + LeafSize(root->right);
}

BTNode* BuyTreeNode(BTData x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->x = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

BTNode* TreeFind(BTNode* root, BTData x)
{
	BTNode* leftRet = NULL;
	BTNode* rightRet = NULL;

	if (root == NULL)
		return NULL;

	if (root->x == x)
		return root;

	leftRet = TreeFind(root->left, x);
	if (leftRet != NULL)
		return leftRet;

	rightRet = TreeFind(root->right, x);
	if (rightRet != NULL)
		return rightRet;

	return NULL;
}

//前序：A B D NULL NULL NULL C E NULL NULL F NULL NULL
//中序：NULL D NULL B NULL A NULL E NULL C NULL F NULL
//后序：NULL NULL D NULL B NULL NULL E NULL NULL F C A

//         A
//     B       C
// D        E      F
int main()
{
	BTNode* A = BuyTreeNode('A');
	BTNode* B = BuyTreeNode('B');
	BTNode* C = BuyTreeNode('C');
	BTNode* D = BuyTreeNode('D');
	BTNode* E = BuyTreeNode('E');
	BTNode* F = BuyTreeNode('F');
	BTNode* G = BuyTreeNode('G');

	A->left = B;
	B->left = D;
	A->right = C;
	C->left = E;
	C->right = F;
	B->right = G;

	//PrevOrder(A);
	//printf("\n");

	//InOrder(A);
	//printf("\n");
	//
	//PostOrder(A);
	//printf("\n");

	//int size = 0;
	//TreeSize1(A, &size);
	//printf("%d\n", size);

	//size = 0;
	//TreeSize1(A, &size);
	//printf("%d\n", size);
	
	//printf("%d\n", TreeSize2(A));

	//printf("%d\n", LeafSize(A));

	//printf("%c\n", TreeFind(A, 'D')->x);
	//if (TreeFind(A, 'Z') == NULL)
	//	printf("not found\n");

	//TreeLevelOrder(A);
	
	//printf("%d\n", BinaryTreeComplete(A));
	
	printf("%d\n", TreeKLevelSize(A, 3));
	return 0;
}

