#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	vector<int>::iterator it = v.begin();
//	v.push_back(1);//���ݺ����ݱ��������µĿռ䣬��it����ԭ����λ�ã�������ʧЧ
//	//����֮��,insert,resize,reserve�ȵȻᵼ�����ݵĽӿڶ����ܵ��µ�����ʧЧ
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	return 0;
//}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator it = v.begin();

	while (it != v.end())
	{
		//����2�����3��VS��ֱ�ӱ���
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			it++;
	}
	for (auto e : v)
		cout << e << ' ';
	cout << endl;
	return 0;
}