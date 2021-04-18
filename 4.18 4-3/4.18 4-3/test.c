//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
//#define MAXSIZE 100
//
//typedef int DataType;
//enum symbol 
//{
//	NUM,
//	OP,
//	EQ,
//	OTHER 
//};//��������
//
//enum oper 
//{ 
//	EPT, 
//	ADD,
//	MIN,
//	MUL,
//	DIV,
//	LEFT,
//	RIGHT 
//}; //�������ͼ����ȼ�
//int Pri[] = { -1, 0, 0, 1, 1, 2, 2 }; //��������ȼ�
//
//union sym {
//	DataType num;
//	enum oper op;
//}; //����ֵ 
//
//enum symbol getSym(union sym *item);
//void operate(enum oper op);//���������
//void compute(enum oper op);//��������
//
//void pushNum(DataType num);
//DataType popNum();
//void pushOp(enum oper op);
//enum oper popOp();
//enum oper topOp();
//
//DataType Num_stack[MAXSIZE]; //����ջ
//int Ntop = -1; //����ջ��ָʾ������ʼΪ��ջ
//enum oper Op_stack[MAXSIZE];//����ջ
//int  Otop = -1; //�����ջ��ָʾ������ʼΪ��ջ
//
//int main()
//{
//	union sym item;
//	enum symbol s;
//	while ((s = getSym(&item)) != EQ) {
//		if (s == NUM)
//			pushNum(item.num);
//		else if (s == OP)
//			operate(item.op);
//		else {
//			printf("Error in the expression!\n");
//			return 1;
//		}
//	}
//	while (Otop >= 0) //��ջ�������������������
//		compute(popOp());
//	if (Ntop == 0) //���������
//		printf("%d\n", popNum());
//	else
//		printf("Error in the expression!\n");
//	return 0;
//}
//
//void error(char s[])
//{
//	fprintf(stderr, "%s\n", s);
//	exit(1);
//}
//
//enum symbol getSym(union sym *item)
//{
//	int  c, n;
//	while ((c = getchar()) != '=') {
//		if (c >= '0' && c <= '9'){
//			for (n = 0; c >= '0' && c <= '9'; c = getchar())
//				n = n * 10 + c - '0';
//			ungetc(c, stdin);
//			item->num = n;
//			return NUM;
//		}
//		else
//			switch (c)  {
//			case '+': item->op = ADD; return OP;
//			case '-': item->op = MIN; return OP;
//			case '*': item->op = MUL; return OP;
//			case '/': item->op = DIV; return OP;
//			case '(': item->op = LEFT; return OP;
//			case ')': item->op = RIGHT; return OP;
//			case ' ' : case '\t': case '\n': break;
//			default: return OTHER;
//		}
//	}
//	return EQ;
//}
//
//void compute(enum oper op)
//{
//	DataType  tmp;
//	switch (op) {
//	case ADD:
//		pushNum(popNum() + popNum()); break;
//	case MIN:
//		tmp = popNum();
//		pushNum(popNum() - tmp); break;
//	case  MUL:
//		pushNum(popNum() * popNum()); break;
//	case DIV:
//		tmp = popNum();
//		pushNum(popNum() / tmp); break;
//	}
//}
//
//����ջ����
//void pushNum(DataType num)
//{
//	if (Ntop == MAXSIZE - 1)
//		error("Data stack is full!");
//	Num_stack[++Ntop] = num;
//}
//DataType popNum()
//{
//	if (Ntop == -1)
//		error("Error in the expression!");
//	return Num_stack[Ntop--];
//}
//
//�����ջ����
//void pushOp(enum oper op)
//{
//	if (Ntop == MAXSIZE - 1)
//		error("Operator stack is full!");
//	Op_stack[++Otop] = op;
//}
//enum operator popOp()
//{
//	if (Otop != -1){
//		return Op_stack[Otop--];
//	}
//	return EPT;
//}
//enum operator topOp()
//{
//	return Op_stack[Otop];
//}
