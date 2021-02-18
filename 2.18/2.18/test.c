#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//
//
//int get_max(int a, int b)
//{
//	return (a) > (b) ? (a) : (b);
//}
//int maxDepth(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	else
//		return 1 + get_max(maxDepth(root->left), maxDepth(root->right));
//}

//bool isEqual(struct TreeNode* s, struct TreeNode* t)
//{
//	if (s == NULL && t == NULL)
//		return true;
//	if (s == NULL || t == NULL)
//		return false;
//	if (s->val != t->val)
//		return false;
//	return isEqual(s->left, t->left) && isEqual(s->right, t->right);
//}
//
//bool isSubtree(struct TreeNode* s, struct TreeNode* t)
//{
//	if (s == NULL)
//		return false;
//	if (isEqual(s, t))
//		return true;
//	return isSubtree(s->left, t) || isSubtree(s->right, t);
//}


int _size(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + _size(root->left) + _size(root->right);
}
void _preorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;
	a[(*pi)] = root->val;
	(*pi)++;
	_preorderTraversal(root->left, a, pi);
	_preorderTraversal(root->right, a, pi);

}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = _size(root);
	int* a = (int*)malloc(sizeof(int)* size);
	printf("%d\n", size);
	*returnSize = size;

	int i = 0;
	_preorderTraversal(root, a, &i);
	return a;
}



//bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	if (p->val != q->val)
//		return false;
//	return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
//}
//
//bool isSymmetric(struct TreeNode* root){
//	if (root == NULL)
//		return true;
//	return _isSymmetric(root->left, root->right);
//}


int main()
{
    
    return 0;
}