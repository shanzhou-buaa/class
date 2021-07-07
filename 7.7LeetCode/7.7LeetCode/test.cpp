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

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		ret.resize(numRows);

		size_t i, j;
		for (i = 0; i < numRows; i++)
		{
			ret[i].resize(i + 1);
			for (j = 0; j <= i; j++)
			{
				if (j == 0 || j == i)
					ret[i][j] = 1;
				else
					ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v = s.generate(5);
	int i;
	return 0;
}