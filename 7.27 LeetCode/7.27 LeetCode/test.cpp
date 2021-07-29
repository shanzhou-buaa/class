#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
	string multiply(string& num1, string& num2)
	{
		int i, j, k;
		int flag = 1;//flag是1为正

		//有一个是0直接输出
		if (num1 == "0" || num2 == "0")
			return "0";

		//两个负数就去掉负号
		if (num1[0] == '-' && num2[0] == '-')
		{
			for (i = 0; i < num1.size(); i++)
				num1[i] = num1[i + 1];
			for (i = 0; i < num2.size(); i++)
				num2[i] = num2[i + 1];
			num1.resize(num1.size() - 1);
			num2.resize(num2.size() - 1);
		}

		//有一个是负数，标记并处理
		if (num1[0] == '-')
		{
			flag = 0;
			for (size_t i = 0; i < num1.size(); i++)
				num1[i] = num1[i + 1];
			num1.resize(num1.size() - 1);
		}
		else if (num2[0] == '-')
		{
			flag = 0;
			for (size_t i = 0; i < num2.size(); i++)
				num2[i] = num2[i + 1];
			num2.resize(num2.size() - 1);
		}

		//全当成正数
		//把char变成int放到vector
		vector<int> v1;
		v1.reserve(num1.size());
		for (i = num1.size() - 1; i >= 0; i--)
			v1.push_back(num1[i] - '0');
		vector<int> v2;
		v2.reserve(num2.size());
		for (i = num2.size() - 1; i >= 0; i--)
			v2.push_back(num2[i] - '0');
		vector<int> v3;
		v3.resize(v1.size() + v2.size());

		//乘
		for (i = 0; i < v1.size(); i++)
		{
			for (j = 0; j < v2.size(); j++)
			{
				v3[i + j] += (v1[i] * v2[j]);
				v3[i + j + 1] += v3[i + j] / 10;
				v3[i + j] %= 10;
			}
		}

		//处理前导0
		while (v3[v3.size() - 1] == 0)
			v3.resize(v3.size() - 1);
		
		string str;
		if (flag == 0)//负数
			str.push_back('-');
		for (k = v3.size() - 1; k >= 0; k--)
			str.push_back(v3[k] + '0');

		return str;
	}
};


int main()
{
	Solution s;
	string num1 = "-123";
	string num2 = "-456";
	cout << s.multiply(num1, num2) << endl;
	return 0;
}