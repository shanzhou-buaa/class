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
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ret;
		ret.resize(digits.size() + 1);
		int i, j, carry;
		ret[0] = digits[digits.size() - 1] + 1;
		if (ret[0] >= 10)
		{
			carry = 1;
			ret[0] -= 10;
		}
		else
			carry = 0;
		for (i = 1, j = digits.size() - 2; j >= 0; i++, j--)
		{
			ret[i] = digits[j] + carry;
			if (ret[i] >= 10)
			{
				carry = 1;
				ret[i] -= 10;
			}
			else
				carry = 0;
		}
		reverse(ret.begin(), ret.end());
		if (carry == 1)
			ret[0] = 1;
		if (ret[0] == 0)
			ret.erase(ret.begin());

		return ret;
	}
};

int main()
{
	vector<int> v = { 0 };
	vector<int> x = Solution().plusOne(v);
	for (auto e : x)
		cout << e << " ";
	cout << endl;
	return 0;
}