////�ļ�ѹ��-Huffmanʵ��
//#define _CRT_SECURE_NO_WARNINGS 1
//#include  <stdio.h>
//#include  <string.h>
//#include  <stdlib.h>
//
//#define  MAXSIZE  32
//
//struct  tnode  {                        //Huffman���ṹ
//	char  c;
//	int  weight;                //���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
//	struct  tnode  *left,*right;
//}  ;
//int  Ccount[128]= {0};               //���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ���
//struct  tnode  *Root=NULL;          //Huffman���ĸ��ڵ�
//char  HCode[128][MAXSIZE]= {{0}}; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ��
//int  Step=0;                        //ʵ�鲽��
//FILE  *Src,  *Obj;
//
//void  statCount();                //����1��ͳ���ļ����ַ�Ƶ��
//void  createHTree();                //����2������һ��Huffman�������ڵ�ΪRoot
//void  makeHCode();                //����3������Huffman������Huffman����
//void  atoHZIP();                  //����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�
//
//void  print1();                        //�������1�Ľ��
//void  print2(struct  tnode  *p);        //�������2�Ľ��
//void  print3();                        //�������3�Ľ��
//void  print4();                        //�������4�Ľ��
//
//int  main() {
//	if((Src=fopen("input.txt","r"))==NULL)  {
//		fprintf(stderr,  "%s  open  failed!\n",  "input.txt");
//		return  1;
//	}
//	if((Obj=fopen("output.txt","w"))==NULL)  {
//		fprintf(stderr,  "%s  open  failed!\n",  "output.txt");
//		return  1;
//	}
//	scanf("%d",&Step);                //���뵱ǰʵ�鲽��
//
//	statCount();                        //ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
//	(Step==1)?print1():1;              //���ʵ�鲽��1���
//	createHTree();                        //ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
//	(Step==2)?print2(Root):2;          //���ʵ�鲽��2���
//	makeHCode();                //ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
//	(Step==3)?print3():3;              //���ʵ�鲽��3���
//	(Step>=4)?atoHZIP(),print4():4;//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���
//
//	fclose(Src);
//	fclose(Obj);
//	return  0;
//}
//void print1() {
//	int i;
//	printf("NUL:1\n");
//	for(i=1; i<128; i++)
//		if(Ccount[i] > 0)
//			printf("%c:%d\n", i, Ccount[i]);
//}
//
//void print2(struct tnode *p) {
//	if(p != NULL) {
//		if((p->left==NULL)&&(p->right==NULL))
//			switch(p->c) {
//				case 0:
//					printf("NUL ");
//					break;
//				case ' ':
//					printf("SP ");
//					break;
//				case '\t':
//					printf("TAB ");
//					break;
//				case '\n':
//					printf("CR ");
//					break;
//				default:
//					printf("%c ",p->c);
//					break;
//			}
//		print2(p->left);
//		print2(p->right);
//	}
//}
//
//void print3() {
//	int i;
//
//	for(i=0; i<128; i++) {
//		if(HCode[i][0] != 0) {
//			switch(i) {
//				case 0:
//					printf("NUL:");
//					break;
//				case ' ':
//					printf("SP:");
//					break;
//				case '\t':
//					printf("TAB:");
//					break;
//				case '\n':
//					printf("CR:");
//					break;
//				default:
//					printf("%c:",i);
//					break;
//			}
//			printf("%s\n",HCode[i]);
//		}
//	}
//}
//
//void print4() {
//	long int in_size, out_size;
//
//	fseek(Src,0,SEEK_END);
//	fseek(Obj,0,SEEK_END);
//	in_size = ftell(Src);
//	out_size = ftell(Obj);
//
//	printf("\nԭ�ļ���С��%ldB\n",in_size);
//	printf("ѹ�����ļ���С��%ldB\n",out_size);
//	printf("ѹ���ʣ�%.2f%%\n",(float)(in_size-out_size)*100/in_size);
//}
//void statCount() {
//	char u;
//	Ccount[0]=1;
//	while((u=fgetc(Src))!=EOF) {
//		Ccount[(int)u]++;
//	}
//}
//int cmp(const void *a,const void *b) {
//	struct tnode **p=(struct tnode**)a;
//	struct tnode **q=(struct tnode**)b;
//	if((*p)->weight!=(*q)->weight)
//		return (*p)->weight-(*q)->weight;
//	else
//		return (*p)->c-(*q)->c;
//}
//void createHTree() {
//	int i,j,n=0;
//	struct tnode *F[128],*p;
//	for(i=0; i<128; i++) {
//		if(Ccount[i]) {
//			p = (struct tnode *)malloc(sizeof(struct tnode));
//			p->c = i;
//			p->weight = Ccount[i];
//			p->left = p->right = NULL;
//			F[n++]=p;
//		}
//	}
//	qsort(F,n,sizeof(struct tnode *),cmp);
//	while(n>1) {
//		p = (struct tnode *)malloc(sizeof(struct tnode));
//		p->weight = F[0]->weight+F[1]->weight;
//		p->left=(struct tnode *)malloc(sizeof(struct tnode));
//		p->right=(struct tnode *)malloc(sizeof(struct tnode));
//		memcpy(p->left,F[0],sizeof(struct tnode));
//		memcpy(p->right,F[1],sizeof(struct tnode));
//		for(i=2; i<n; i++) {
//			if(F[i]->weight>p->weight) {
//				if(i==2) {
//					memcpy(F[1],p,sizeof(struct tnode));
//					for(j=0; j<n-1; j++)
//						memcpy(F[j],F[j+1],sizeof(struct tnode));
//				} else {
//					for(j=1; j<i-1; j++)
//						memcpy(F[j],F[j+1],sizeof(struct tnode));
//					memcpy(F[i-1],p,sizeof(struct tnode));
//					for(j=0; j<n-1; j++)
//						memcpy(F[j],F[j+1],sizeof(struct tnode));
//				}
//				break;
//			} else if(i==n-1&&F[i]->weight<p->weight) {
//				for(j=0; j<n-2; j++)
//					memcpy(F[j],F[j+2],sizeof(struct tnode));
//				memcpy(F[j],p,sizeof(struct tnode));
//			}
//		}
//		n--;
//	}
//	Root=p;
//}
//
//void visitHTree(struct tnode *p,char *s,int cur) {
//	if(p!=NULL) {
//		if(p->left==NULL && p->right==NULL) {
//			s[cur]='\0';
//			strcpy(HCode[p->c],s);
//			return;
//		}
//		s[cur]='0';
//		visitHTree(p->left,s,cur+1);
//		s[cur]='1';
//		visitHTree(p->right,s,cur+1);
//	}
//}
//void makeHCode() {
//	char s[2000];
//	memset(s,'\0',2000);
//	visitHTree(Root,s,0);
//}
//char s[200000],s1[200000];
//void atoHZIP() {
//	int i,j,hc=0;
//	Src=fopen("input.txt","r");
//	fread(s,sizeof(char),200000,Src);
//	for(i=0; s[i]!='\0'; i++) {
//		strcat(s1,HCode[s[i]]);
//	}
//	strcat(s1,HCode[0]);
//	for(i=0;s1[i]!='\0'||(i+1)%8!=0;i++) {
//		if(s1[i]!='\0')
//			hc = (hc << 1) | (s1[i]-'0');
//		else
//			hc = (hc << 1) | 0;
//		if((i+1)%8 == 0) {
//			fputc(hc,Obj);     //�����Ŀ�꣨ѹ�����ļ���
//			printf("%x",hc);   //��ʮ�������������Ļ��
//			hc=0;
//		}
//	}
//}
//
