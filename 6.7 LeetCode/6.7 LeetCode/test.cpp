#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class A
{
	friend class Solution;
public:
	A()
	{
		_ret += _i;
		_i++;
	}
private:
	static int _i;
	static int _ret;
};

int A::_i = 1;
int A::_ret = 0;

class Solution {
public:
	int sumNums(int n)
	{
		A::_ret = 0;
		A::_i = 1;
		A* a = new A[n];
		return A::_ret;
	}
};

int main()
{
	Solution s1;
	int x;
	while (scanf("%d", &x) != EOF)
		cout << (s1.sumNums(x)) << endl;
	return 0;
}