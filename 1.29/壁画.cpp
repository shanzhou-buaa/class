#include <stdio.h>
int main()
{
	long long int l[101]={0},r[101]={0},s[101]={0}; //s�������ÿ���ڻ����� 
	int n, i;
	scanf("%d", &n);
	long long int a, b, sum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a, &b);
		l[i] = a;
		r[i] = b;
	}
	for (i = 0; i < n - 1; i++)
	{
		s[i] = r[i] - l[i]; //���ÿ���ڻ����� 
		s[i + 1] = r[i + 1] - l[i + 1];
		if(i == 0)
		{ 
		if(r[i] <= l[i + 1])	
			sum = s[i] + s[i + 1]; //���ص�ֱ����� 
		else  
			sum = s[i] + s[i + 1] -(r[i] - l[i + 1]); //�ص�ʱ��ȥ�ص����� 
		}
		else	
		{ 
		if(r[i] <= l[i + 1])
			sum = sum + s[i + 1];
		else  
			sum = sum + s[i + 1] - (r[i] - l[i + 1]);
		}
	}
	printf("%lld\n", sum);
	return 0;
}

