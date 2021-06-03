#define _CRT_SECURE_NO_WARNINGS 1

//�ļ�ѹ��-Huffmanʵ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman���ṹ
	char c;						//�ַ�
	int weight;					//���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
	struct tnode *left,*right;
}; 
int Ccount[128]={0};			//���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ��� 
struct tnode *Root=NULL; 		//Huffman���ĸ��ڵ�
char HCode[128][MAXSIZE]={{0}}; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ�� 
int Step=0;						//ʵ�鲽�� 
FILE *Src, *Obj;				//SrcΪ�����ļ���ָ�룬ObjΪ����ļ���ָ��
	
void statCount();				//����1��ͳ���ļ����ַ�Ƶ��
void createHTree();				//����2������һ��Huffman�������ڵ�ΪRoot 
void makeHCode();				//����3������Huffman������Huffman����
void atoHZIP(); 				//����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�

void print1();					//�������1�Ľ��
void print2(struct tnode *p);	//�������2�Ľ�� 
void print3();					//�������3�Ľ��
void print4();					//�������4�Ľ��

void PreOrder(struct tnode* root, int index, char* s);

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//���뵱ǰʵ�鲽�� 
	
	statCount();						//ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
	(Step==1) ? print1(): 1; 			//���ʵ�鲽��1���	
	createHTree();						//ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
	(Step==2) ? print2(Root): 2; 		//���ʵ�鲽��2���	
	makeHCode();				   		//ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
	(Step==3) ? print3(): 3; 			//���ʵ�鲽��3���
	(Step>=4) ? atoHZIP(),print4(): 4; 	//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//��ʵ�鲽��1����ʼ 

void statCount()
{
	Ccount[0] = 1;
	while (1)
	{
		char c = fgetc(Src);
		if (c == EOF)
			break;
		Ccount[c]++;
	}
}

//��ʵ�鲽��1������

//��ʵ�鲽��2����ʼ

void createHTree()
{
	struct tnode* tree[130];
	int i = 0, j = 0, index = 0;//index��tree������ָ��ĸ���
	for (i = 0; i < 130; i++)//��0��ʼ
		tree[i] = NULL;

	//�����ַŽ�treeָ��������
	for (i = 0; i < 128; i++)
	{
		if (Ccount[i] > 0)
		{
			struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
			node->c = i;
			node->weight = Ccount[i];
			node->left = NULL;
			node->right = NULL;

			tree[index++] = node;
		}
	}

	//����
	i = 0, j = 0;
	for (i = 0; i < index - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < index - i - 1; j++)
		{
			if (tree[j]->weight > tree[j + 1]->weight)
			{
				flag = 0;
				struct tnode* temp = tree[j];
				tree[j] = tree[j + 1];
				tree[j + 1] = temp;
			}
		}
		if (flag)
			break;
	}
	
	struct tnode* root = NULL;
	while (index > 1)
	{
		int init = index;
		//����һ������
		root = (struct tnode*)malloc(sizeof(struct tnode));
		struct tnode* t0 = (struct tnode*)malloc(sizeof(struct tnode));
		struct tnode* t1 = (struct tnode*)malloc(sizeof(struct tnode));
		root->left = t0;
		root->right = t1;
		memcpy(t0, tree[0], sizeof(struct tnode));
		memcpy(t1, tree[1], sizeof(struct tnode));
		//root->c = t0->c + t1->c;
		root->weight = t0->weight + t1->weight;
		tree[0]->weight = -1;
		tree[1]->weight = -1;

		//�Ѻ����ָ����ǰŲ
		for (i = 0, j = 0; i < index; i++)
		{
			if (tree[i]->weight == -1)
				continue;
			
			//���Ǳ�ɾ����ָ����ȨֵС��root
			if (tree[i]->weight < root->weight)
				memcpy(tree[j++], tree[i], sizeof(struct tnode));
			
			//������ȵģ��ŵ���һ���������
			if (tree[i]->weight == root->weight)
			{
				while (tree[i]->weight == root->weight)
					memcpy(tree[j++], tree[i++], sizeof(struct tnode));
				memcpy(tree[j++], root, sizeof(struct tnode));
				break;
			}
			if (j > 1 && tree[i]->weight > root->weight && tree[j - 1]->weight < root->weight)
			{
				memcpy(tree[j++], root, sizeof(struct tnode));
				break;
			}
		}

		//root������
		if (i == index)
			memcpy(tree[j++], root, sizeof(struct tnode));

		while (i < index)
			memcpy(tree[j++], tree[i++], sizeof(struct tnode));

		index--;
		//for (i = index; i < init; i++)
			//memset(tree[i], 0, sizeof(struct tnode));
	}
	
	Root = root;
}

//��ʵ�鲽��2������

//��ʵ�鲽��3����ʼ

void PreOrder(struct tnode* root, int index, char* s)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			s[index] = '\0';
			strcpy(HCode[root->c], s);
			return;
		}
		s[index] = '0';
		PreOrder(root->left, index + 1, s);
		s[index] = '1';
		PreOrder(root->right, index + 1, s);
	}
	else
		return;
}

void makeHCode()
{
	char s[40];
	int index = 0;
	PreOrder(Root, index, s);
} 

//��ʵ�鲽��3������

//��ʵ�鲽��4����ʼ

void atoHZIP()
{
	char s[5005];
	char code[10005];
	memset(code, 0, 10005);
	rewind(Src);
	int len = fread(s, 1, 5000, Src);
	int hc = 0, i;
	//���������ַ����н���Huffman���봮���ӳ�һ����0��1�ַ���ɵĴ�
	for (i = 0; i < len; i++)
		strcat(code, HCode[s[i]]);
	strcat(code, HCode[0]);
	int len1 = strlen(code);
	for (i = 0; code[i] != '\0'; i++)
	{
		hc = (hc << 1) | (code[i] - '0');
		if ((i + 1) % 8 == 0)
		{
			fputc(hc, Obj);     //�����Ŀ�꣨ѹ�����ļ���
			printf("%x", hc);   //��ʮ�������������Ļ��
			hc = 0;
		}
	}
	if (len1 % 8 != 0)
	{
		int remain = len1 % 8;
		int x = 0;
		for (i = 0; i < remain; i++)
			x = (x << i) | (hc << i);
		fputc(x, Obj);
		printf("%x", x);
	}
}

//��ʵ�鲽��4������

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\nԭ�ļ���С��%ldB\n",in_size);
	printf("ѹ�����ļ���С��%ldB\n",out_size);
	printf("ѹ���ʣ�%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
