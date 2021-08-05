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
class Solution1 {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (auto& e : nums)
		{
			if (e < 0)
				e = -e;
		}
		sort(nums.begin(), nums.end());
		for (auto& e : nums)
			e = e * e;

		return nums;
	}
};

class Solution
{
public:
	string reverseOnlyLetters(string& s)
	{
		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			while (left < right && !isalpha(s[left]))
				left++;
			while (left < right && !isalpha(s[right]))
				right--;

			swap(s[left], s[right]);
			left++;
			right--;
		}

		return s;
	}
};
int main()
{
	string s = "ab-cd";
	cout << Solution().reverseOnlyLetters(s) << endl;
	return 0;
}