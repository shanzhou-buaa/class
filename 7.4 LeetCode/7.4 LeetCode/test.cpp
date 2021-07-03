#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	int n = 0;
	for (size_t i = 0; i < v.size(); i++)
		n ^= v[i];

	cout << n << endl;
	return 0;
}