//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//#include<ctype.h>
///**************************   �������ʽ���ĺ���      ******************/
//typedef struct TreeNode{  //���Ľṹ�� 
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//}Tree, *Treep;
//
//Treep TreeStack[2021], tmp, p, q;  //��ջ 
//int OpStack[2021];              //�����ջ 
//int treeTop = 0, opTop = 0;
//
//void  pushOp(int *s, int item) //�����ջѹջ 
//{
//	s[opTop] = item;
//	opTop++;
//}
//void  pushTree(Treep *s, Treep item)//��ջѹջ
//{
//	s[treeTop] = item;
//	treeTop++;
//}
//int popOp(int *s)//�����ջ��ջ
//{
//	return s[--opTop];
//}
//Treep popTree(Treep *s)//��ջ��ջ
//{
//	Treep p = (Treep)malloc(sizeof(Tree));
//	memcpy(p, s[treeTop - 1], sizeof(struct TreeNode));  //�������ڵ���Ϣ 
//	s[treeTop - 1] = NULL;  //����ջ��ĵ����Ľڵ���� 
//	treeTop--;
//	return p;
//}
//int GetOpTop(int *s)  //��������ջ��ջ��Ԫ�� 
//{
//	return s[opTop - 1];
//}
//int GetTreeTop(Treep *s) //�����ջ��ջ��Ԫ�� 
//{
//	return s[treeTop - 1]->val;
//}
//Treep CreateLeaves(int item)  //����һ���µ�Ҷ�ӽڵ� 
//{
//	Treep q = (Treep)malloc(sizeof(Tree));
//	q->left = NULL;
//	q->right = NULL;
//	q->val = item;
//	return q;
//}
//int IsTheta(char c) //�ж��Ƿ�Ϊ������������������1�������Ƿ���0
//{
//	switch (c){
//	case '+':
//	case '-':
//	case '*':
//	case '/':
//	case '(':
//	case ')':
//	case '=':
//		return 1;
//	default:
//		return 0;
//	}
//}
//char Precede(char theta1, char theta2)   //��������ȼ��Ƚ� 
//{
//	int i, j;
//	char pre[7][7] = {// +   -   *   /   (   )   = 
//		{ '>', '>', '<', '<', '<', '>', '>' },
//		{ '>', '>', '<', '<', '<', '>', '>' },
//		{ '>', '>', '>', '>', '<', '>', '>' },
//		{ '>', '>', '>', '>', '<', '>', '>' },
//		{ '<', '<', '<', '<', '<', '=', '0' },
//		{ '>', '>', '>', '>', '0', '>', '>' },
//		{ '<', '<', '<', '<', '<', '0', '=' } };
//
//	switch (theta1){
//	case '+': i = 0; break;
//	case '-': i = 1; break;
//	case '*': i = 2; break;
//	case '/': i = 3; break;
//	case '(': i = 4; break;
//	case ')': i = 5; break;
//	case '=': i = 6; break;
//	}
//
//	switch (theta2){
//	case '+': j = 0; break;
//	case '-': j = 1; break;
//	case '*': j = 2; break;
//	case '/': j = 3; break;
//	case '(': j = 4; break;
//	case ')': j = 5; break;
//	case '=': j = 6; break;
//	}
//	return(pre[i][j]);
//}
//int Operate(int a, char theta, int b)    //����������� 
//{
//	int result;
//
//	switch (theta){
//	case'+':return a + b;
//	case'-':return a - b;
//	case'*':return a*b;
//	case'/':             //�жϳ����Ƿ�Ϊ0��������Ϊ�㷵�ش�����ʾ                       
//		if (b != 0)
//			return a / b;
//		else
//		{
//			printf("Divisor can not Be zero!\n");
//			exit(0);
//		}
//	}
//
//}
//
////*************************************************�������ʽ��
//
//void CreateExpressionTree(char *expression)
//{
//	int theta, X1, X2;
//	Treep a, b, tmp;
//	char ch;
//	int i = 0;
//	pushOp(OpStack, '=');
//	ch = expression[i++];		// ch ��ȡ���ʽ����һ���ַ�
//	while (ch != '=' || GetOpTop(OpStack) != '=')
//	{
//		if (IsTheta(ch)) //�ж��Ƿ�Ϊ����� 
//		{
//			switch (Precede(GetOpTop(OpStack), ch)) // �Ƚ� ch ��ջ������������ȼ�
//			{
//			case'<':
//				pushOp(OpStack, ch);
//				ch = expression[i++];
//				break;
//			case'>':
//				theta = popOp(OpStack);
//				p = CreateLeaves(theta);
//				b = popTree(TreeStack);//�������������µĵĽڵ��γ�һ�������������ǣ� 
//				a = popTree(TreeStack);
//				p->left = (Treep)malloc(sizeof(Tree));
//				p->right = (Treep)malloc(sizeof(Tree));
//				memcpy(p->left, a, sizeof(struct TreeNode));
//				memcpy(p->right, b, sizeof(struct TreeNode));
//				pushTree(TreeStack, p);
//				break;
//			case'=':
//				popOp(OpStack);
//				ch = expression[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//				break;
//			}
//
//		}
//		else if (isdigit(ch)) //�ж��Ƿ�Ϊ���� 
//		{
//			X1 = ch - '0'; //���ַ���ʽת��Ϊ����
//			p = CreateLeaves(X1);
//			pushTree(TreeStack, p);
//			X2 = X1;
//			ch = expression[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//
//			while (isdigit(ch)) //�ж���һλ�Ƿ�������
//			{
//				X1 = ch - '0';
//				X2 = 10 * X2 + X1; //�鲢��X2
//				tmp = popTree(TreeStack);
//				p = CreateLeaves(X2);
//				pushTree(TreeStack, p);
//				ch = expression[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//			}
//		}
//		else if (ch == ' ') //�ж��Ƿ�Ϊ�ո�
//		{
//			while (ch == ' ')
//			{
//				ch = expression[i++];
//			}
//		}
//		else //���ַǷ��ַ� 
//		{
//			printf("Input has illegal characters!\n");
//			printf("Please enter again.\n");
//			exit(0); //���ش�����ʾ
//		}
//	}
//
//}
//int EvaluateExpression(Treep T)
//{
//	if (T->left&&T->right)
//	{
//		if (T->left->left || T->left->right)
//			EvaluateExpression(T->left);
//		if (T->right->left || T->right->right)
//			EvaluateExpression(T->right);
//
//		T->val = Operate(T->left->val, T->val, T->right->val);
//		free(T->left);
//		free(T->right);
//		T->left = T->right = NULL;
//		return T->val;
//	}
//	return T->val;
//}
//void VISIT(Treep t)  //�������ڵ� 
//{
//	if (t->val == '/' || t->val == '+' || t->val == '-' || t->val == '*')	printf("%c ", t->val);
//	else printf("%d ", t->val);
//}
//void inorder(Treep t)  //������� 
//{
//	if (t != NULL){
//		inorder(t->left);
//		VISIT(t);      // ����tָ�Ľ�� 
//		inorder(t->right);
//	}
//}
//void PrintTree(Treep root)  //��ӡ���ڵ���Ϣ 
//{
//	if (root == NULL) printf("\n");
//	else
//	{
//		if (root->val == '/' || root->val == '+' || root->val == '-' || root->val == '*')
//			printf("%c ", root->val);
//		else	printf("%d ", root->val);
//		if (root->left != NULL)
//		{
//			if (root->left->val == '/' || root->left->val == '+' || root->left->val == '-' || root->left->val == '*')
//				printf("%c ", root->left->val);
//			else
//				printf("%d ", root->left->val);
//		}
//		if (root->right != NULL)
//		{
//			if (root->right->val == '/' || root->right->val == '+' || root->right->val == '-' || root->right->val == '*')
//				printf("%c ", root->right->val);
//			else
//				printf("%d ", root->right->val);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	char expression[2021];
//	int result;
//	gets(expression);
//	CreateExpressionTree(expression);
//	//inorder(TreeStack[0]);
//	PrintTree(TreeStack[0]);
//	printf("%d\n", EvaluateExpression(TreeStack[0]));
//	return 0;
//}