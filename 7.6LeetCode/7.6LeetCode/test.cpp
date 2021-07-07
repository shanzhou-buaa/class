#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto e : nums)
			val ^= e;

		size_t i = 0;
		for (i = 0; i < 32; i++)
		{
			if (((val >> i) & 1) == 1)
				break;
		}

		vector<int> ret(2, val);
		for (auto e : nums)
		{
			if (((e >> i) & 1) == 1)
				ret[0] ^= e;
			else
				ret[1] ^= e;
		}

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> input = { 1, 2, 1, 3, 2, 5 };
	vector<int> v = s.singleNumber(input);
	for (auto e : v)
		cout << e << endl;
	return 0;
}