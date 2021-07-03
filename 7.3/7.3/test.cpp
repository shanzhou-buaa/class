#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//string和vector<char>
//string里有\0
//vecotr不支持+=等等

void test1();
void test2();
void test3();
void test4();
void print_vector(const vector<int>& vt);

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	vector<int> v2(v1);
	for (size_t i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	for (size_t i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(40);
	v3.push_back(50);
	v1 = v3;
	for (size_t i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
}

void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	//三种迭代器
	vector<int>::iterator  it = v1.begin();
	while (it != v1.end())
	{
		*it *= 10;
		cout << *it << ' ';
		it++;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	for (auto e : v1)
	{
		e /= 10;
		cout << e << ' ';
	}
	cout << endl;
}

void print_vector(const vector<int>& vt)
{
	vector<int>::const_iterator cit = vt.begin();
	while (cit != vt.end())
	{
		//*cit += 10;//const迭代器不能写
		cout << *cit << ' ';
		cit++;
	}
	cout << endl;
}

void test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test4()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(52);
	v.push_back(60);
	v.push_back(1);
	v.push_back(99);

	//查找区间[v.begin(), v.end())左闭右开
	vector<int>::iterator pos = find(v.begin(), v.end(), 52);
	if (pos != v.end())
		v.erase(pos);
	for (auto e : v)
		cout << e << ' ';
	cout << endl;

	sort(v.begin(), v.end());
	for (auto e : v)
		cout << e << ' ';
	cout << '\n';
}