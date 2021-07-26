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

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<int> arr;
		arr.resize(26);
		for (auto& e : arr)
			e = 0;

		int flag = 0;
		for (auto e : str)
		{
			arr[e - 'a']++;
		}

		for (size_t i = 0; i < str.size(); i++)
		{
			if (arr[str[i] - 'a'] == 1)
			{
				flag = 1;
				cout << str[i] << endl;
				break;
			}
		}
		if (!flag)
			cout << -1 << endl;
	}

	return 0;
}