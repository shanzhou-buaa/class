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

//为什么会有list？补充vector的缺点
//vector的缺点：
//1.头部、中部插入删除效率低
//2.插入数据空间不够时需要增容。增容要开新空间、拷贝数据、释放就空间，代价较大
//vector的优点：支持下标的随机访问，间接支持排序、二分、堆

void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test1();
void test2();
void test3();

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}

void test1()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	l.push_front(0);
	l.push_front(-1);
	l.push_front(-2);

	for (auto e : l)
		cout << e << " ";
	cout << endl;

	l.pop_back();
	l.pop_front();

	for (auto e : l)
		cout << e << " ";
	cout << endl;


	list<int>::reverse_iterator rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test2()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	print_list(l1);

	list<int> l2;
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	l2.push_back(40);

	l1 = l2;
	print_list(l1);
}

void test3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	print_list(l);

	list<int>::iterator pos = find(l.begin(), l.end(), 3);
	if (pos != l.end())
		l.insert(pos, 30);
	print_list(l);

	//insert以后pos迭代器没失效
	l.erase(pos);
	print_list(l);

	//vector的insert调用后迭代器会失效
}