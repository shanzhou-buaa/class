#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	size_t pos = s1.rfind(' ');
	if (pos != s1.npos)
	{
		cout << s1.size() - pos - 1 << endl;
	}
	else
		cout << s1.size() << endl;
	return 0;
}