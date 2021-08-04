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
	bool isLongPressedName(string name, string typed) {
		size_t i = 0, j = 0;
		while (j < typed.size())
		{
			if (i < name.size() && name[i] == typed[j])
			{
				i++;
				j++;
			}
			else if (j > 0 && typed[j] == typed[j - 1])
				j++;
			else
				return false;
		}
		if (i == name.size())
			return true;
		else
			return false;
	}
};
int main()
{

	return 0;
}