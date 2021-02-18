 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef int BTD;
//BinaryTreeData


typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	//struct BinaryTreeNode* parent;
	BTD data;
}BT;



//前序遍历：根	左子树	右子树
//中序遍历：左子树	根	右子树
//后序遍历：左子树	右子树	根

//二叉树结点个数
int BinaryTreeSize(BT* root)
{
	if (root == NULL)
		return 0;   
	else
		return  1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}


//二叉树叶子结点个数
int BinaryTreeLeafSize(BT* root)
{
	if (root->left == NULL && root->right == NULL)
		return 1;
	else if (root == NULL)
		return 0;
	else
		return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


//二叉树第k层结点个数
int BinaryTreeLevelKSize(BT* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}