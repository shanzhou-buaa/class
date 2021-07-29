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
class Solution
{
public:
	string addStrings(string& num1, string& num2)
	{
		if (num1 == "0")
			return num2;
		else if (num2 == "0")
			return num1;

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string more = num1;
		string less = num2;
		if (num2.size() > num1.size())
		{
			more = num2;
			less = num1;
		}

		vector<int> ret;
		ret.resize(more.size() + 1);
		size_t i = 0, carry = 0;
		while (i < less.size())
		{
			int temp = more[i] + less[i] - 2 * '0';
			ret[i] += temp;
			carry = ret[i] / 10;
			ret[i] %= 10;
			if (carry > 0)
			{
				ret[i + 1] += carry;
				carry = 0;
			}
			i++;
		}
		while (i < more.size())
		{
			ret[i] += more[i] - '0';
			if (ret[i] >= 10)
			{
				ret[i] -= 10;
				ret[i + 1] += 1;
			}
			i++;
		}
		while (ret[ret.size() - 1] == 0)
			ret.resize(ret.size() - 1);
		string str;
		str.resize(ret.size());
		for (i = 0; i < ret.size(); i++)
			str[i] = ret[i] + '0';
		reverse(str.begin(), str.end());

		return str;
	}
};
int main()
{
	Solution s;
	string str1 = "99";
	string str2 = "1";
	cout << s.addStrings(str1, str2) << endl;
	return 0;
}