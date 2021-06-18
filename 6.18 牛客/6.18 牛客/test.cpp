#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;
#include <ctype.h>
class Solution
{
public:
	char AlphaNum(char c)
	{
		if (isalpha(c))
			c = tolower(c);
		return c;
	}
	bool isPalindrome(string s)
	{
		if (s == " ")
			return true;

		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isalnum(s[begin]))
				begin++;
			while (begin < end && !isalnum(s[end]))
				end--;
			char a = AlphaNum(s[begin]);
			char b = AlphaNum(s[end]);
			if (a != b)
				return false;
			begin++;
			end--;
		}
		return true;
	}
};
int main()
{
	string s = "0p";
	Solution sol;
	cout << sol.isPalindrome(s) << endl;
	return 0;
}