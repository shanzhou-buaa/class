#define _CRT_SECURE_NO_WARNINGS 1

//a = -5
//b = -12
//c = -17
#include <string.h>
#include <stdio.h>

//void sstrcat(char* s, char* t)
//{
//	int n = strlen(s);
//	while (*(s + n) = *t)
//	{
//		s++;
//		t++;
//	}
//}
//int main()
//{
//	char s1[] = "abcd";
//	char s2[] = "efgh";
//	sstrcat(s1, s2);
//	printf("%s", s1);
//	return 0;
//}


//typedef struct stu
//{
//	int num;
//	float score;
//}s;
//
//void f(s p)
//{
//	s s1[2] = { { 20044, 550 }, { 20045, 537 } };
//	p.num = s1[1].num;
//	p.score = s1[1].score;
//}
//
//int main()
//{
//	s s1[2] = { { 20041, 703 }, { 20042, 580 } };
//	f(s1[0]);
//	printf("%d %3.0f\n", s1[0].num, s1[0].score);
//	return 0;
//}

//struct st
//{
//	int x;
//	int* y;
//}*pt;
//
//int main()
//{
//	int a[] = { 1, 2 };
//	int b[] = { 3, 4 };
//	struct st c[2] = { 10, a, 20, b };
//	pt = c;
//	printf("%d\n", ++pt->x);
//	return 0;
//}


struct dent
{
	int n;
	int* m;
};

int main()
{
	int a = 1, b = 2, c = 3;
	struct dent s[3] = { { 101, &a }, { 102, &b }, { 103, &c } };
	struct dent* p = s;
	printf("%d\n", *(++p)->m);
	return 0;
}