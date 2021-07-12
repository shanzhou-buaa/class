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
#include <stack>
#include <queue>
using namespace std;

void test1();
void test2();

int main()
{
	//test1();
	test2();
	return 0;
}

void test1()
{
	stack<double> st;
	st.push(1.1);
	st.push(2.2);
	st.push(3.3);
	st.push(4.4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test2()
{
		queue<double> q;
		q.push(1.1);
		q.push(2.2);
		q.push(3.3);
		q.push(4.4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
}