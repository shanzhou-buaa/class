//#define _crt_secure_no_warnings 1
//
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//
////#define range1 97
////#define range2 122
//#define range1 32
//#define range2 126
//
//
//typedef struct listnode
//{
//	char c;
//	struct listnode* next;
//}listnode;
//
//int main()
//{
//	file* in = fopen("in.txt", "r");
//	file* out = fopen("in_crpyt.txt", "w");
//	char secret[40] = { 0 };
//	gets(secret);//��ʼ��Կ
//	int len = strlen(secret);
//	int i = 0, j = 0, k = 0;
//
//	//ɾ���ظ��ַ�
//	//c programming(second edition)
//	//c progamin(secdet)
//	for (i = 0; i < len; i++)
//	{
//		for (j = i + 1; j < len; j++)
//		{
//			if (secret[i] == secret[j])
//			{
//				for (k = j; k < len - 1; k++)
//				{
//					secret[k] = secret[k + 1];
//				}
//				secret[k] = '\0';
//				len--;
//			}
//		}
//	}
//
//	//����ѭ������
//	listnode* head = null;
//	listnode* cur = null;
//	listnode* next = null;
//	for (i = 0; i < len; i++)
//	{
//		next = (listnode*)malloc(sizeof(listnode));
//		next->c = secret[i];
//		if (head == null)
//		{
//			head = next;
//			cur = next;
//		}
//		else
//		{
//			cur->next = next;
//			cur = cur->next;
//		}
//	}
//	//cur,next��ָ�����һ���ַ�
//	//cur->next��next->next��Ϊ���ֵ
//
//	//������Կ��
//	char ch = range1;
//	for (; ch <= range2; ch++)
//	{
//		int flag = 1;
//		for (i = 0; i < len; i++)
//		{
//			if (secret[i] == ch)
//			{
//				flag = 0;
//			}
//		}
//		if (flag)
//		{
//			next = (listnode*)malloc(sizeof(listnode));
//			next->c = ch;
//			cur->next = next;
//			cur = cur->next;
//		}
//	}
//	int len2 = range2 - range1 + 1;
//	listnode* tail = cur;
//	tail->next = head;
//
//	char secret1[200] = { 0 };
//	for (cur = head, i = 0; cur->next != head; cur = cur->next, i++)
//		secret1[i] = cur->c;
//	secret1[i] = cur->c;//��ѭ������������ݷŵ�secret1��//����
//	char secret2[200] = { 0 };
//
//	//������Կ
//	cur = head;//�ڵ�
//	listnode* prev = tail;
//	char a = 0;//asc��
//	while (len2 > 0)//һ�η���һ��
//	{
//		i = 0;
//		while (cur->c == 0)//���ַ���Ϊ0�Ľ��
//		{
//			cur = cur->next;
//		}
//		a = cur->c;//ascii��ŵ�a��
//
//		cur->c = 0;//����һλ��������λԪ�� 
//		cur = cur->next;
//
//		//ɾ��0���
//		if (cur->next->c == 0)//�����һ����0
//		{
//			listnode* temp = cur;
//			//while (temp->next->c != cur->c)//����⣬�����һ����0����һֱ�����ң�ֱ��temp��cur��ȣ�
//			while (temp->next->c == 0)//�ĳ�һֱ��ֱ������0
//			{
//				temp = temp->next;
//			}
//			prev = temp;//0
//			cur = temp->next;
//		}
//		else//�������0��������
//		{
//			prev->next = cur->next;
//			prev = cur;
//		}
//
//		//cur->c = 0;//����һλ��������λԪ��//�ŵ�ǰ�棿
//		//cur = cur->next;
//
//		len2--;
//
//		if (len2 == 0)
//			break;
//
//		//ǰ������
//		int step = 0;
//		if (len2 != 0)
//		{
//			step = a % len2 - 1;
//		}
//		if (step < 0)//���<0���ʾ�պûص�ԭλ
//		{
//			step = len2 - 1;
//		}
//
//		//�ҵ���Ӧ����ĸ
//		while (step--)
//		{
//			while (cur->next->c == 0)//�����һ����0������
//				cur = cur->next;
//			while (prev->next->c == 0)//�����һ����0������
//				prev = prev->next;
//			prev = prev->next;//����һ��
//			cur = cur->next;//����һ��
//		}
//		secret2[a - range1] = cur->c;//�ѵõ����ַ�����ȥ//Ϊʲô��ô�棬����˳���
//	}
//	secret2[a - range1] = a;
//
//	char s[1024] = { 0 };
//	int len4 = strlen(secret2);
//	int pos = 0;
//
//	while (fgets(s, 1000, in) != null)
//	{
//		int len3 = strlen(s);
//		for (i = 0; i < len3; i++)
//		{
//			for (j = 0; j < len4; j++)
//			{
//				if (s[i] == secret1[j])
//				{
//					pos = j;
//					break;
//				}
//			}
//			fputc(secret2[pos], out);
//		}
//	}
//
//	fclose(in);
//	fclose(out);
//	return 0;
//}
//
////char news1[100] = { 0 };
////for (i = 0; i <= range2 - range1; i++)
////news1[i] = i + range1;
////char news2[100] = { 0 };
////for (cur = head, next = head; len2 > 0;)
////{
////	int step = next->c, pos = 0;
////	len2--;
////	for (i = 0; i <= range2 - range1; i++)
////	{
////		if (news1[i] == step)
////		{
////			pos = i;
////			break;
////		}
////	}
////	if (next == head)
////	{
////		tail->next = next->next;
////		next = next->next;
////	}
////	else
////	{
////		listnode* f = next;
////		if (cur == head)
////			tail->next = next->next;
////		else
////			cur->next = next->next;
////		next = next->next;
////		cur = cur->next;
////	}
////	listnode* temp = next;
////	if (len2 != 0)
////	{
////		step %= len2;
////		for (i = 0; i < step - 1; i++)
////			temp = temp->next;
////	}
////	news2[pos] = temp->c;
////}