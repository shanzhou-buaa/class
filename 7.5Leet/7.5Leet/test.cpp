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

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	//0010 * 3
	//0011
	//... 1  0
	//... 4  1
	vector<int> ret(32, 0);

	size_t i, j;
	for (i = 0; i < v.size(); i++)
	{
		int x = v[i];
		for (j = 0; j < 32; j++)
		{
			if (((x >> j) & 1) == 1)
			{
				ret[j]++;
			}
		}
	}
	int val = 0;
	for (j = 0; j < 32; j++)
	{
		if (ret[j] % 3 == 1)
		{
			val |= (1 << j);
		}
	}

	cout << val << endl;
	return 0;
}