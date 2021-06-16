#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main()
//{
//	string s1;
//	cout << "size:" << s1.size() << endl;
//	cout << "capacity:" << s1.capacity() << endl;
//	cout << s1 << endl;
//
//	//让size变成新的值，多出来的默认填'\0'
//	//但最后一个位置一定是'\0'
//	s1.resize(20, 'a');
//	cout << "size:" << s1.size() << endl;
//	cout << "capacity:" << s1.capacity() << endl;
//	cout << s1 << endl;
//
//	string s2 = "hello world";
//	s2.resize(20, '1');
//	cout << s2 << endl;
//
//	s2.resize(5);
//	cout << s2 << endl;
//
//	return 0;
//}

//int main()
//{
//	//开100个int，初始化为0
//	vector<int> v;
//	v.resize(100, 0);
//
//	string s3;
//	s3.reserve(127);
//	int capacity = s3.capacity();
//	for (char ch = 0; ch < 127; ch++)
//	{
//		s3 += ch;
//		//多次增容
//		if (capacity != s3.capacity())
//		{
//			printf("增容：%d->%d\n", capacity, s3.capacity());
//			capacity = s3.capacity();
//		}
//	}
//	cout << s3 << endl;
//	
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world";
//	s1.resize(20);
//	s1 += "!!!";
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;//遇到'\0'就停止，后面可能有字符，但不会输出后面的字符
//	return 0;
//}

string GetProtocol(const string& url)
{
	size_t pos = url.find("://");
	if (pos != url.npos)
		return url.substr(0, pos);
	else
		return string();//返回空串
}

string GetDomain(const string& url)
{
	size_t pos = url.find("://");
	if (pos != url.npos)
	{
		size_t start = pos + 3;//跳过://
		size_t end = url.find('/', start);
		if (end != url.npos)
			return url.substr(start, end - start);
		else
			return string();
	}
	else
		return string();
}

//int main()
//{
//	string filename = "article.txt.c";
//	size_t pos = filename.rfind('.');
//	if (pos != string::npos)
//	{
//		string sub1(filename, pos, filename.size() - pos);
//		cout << sub1 << endl;
//
//		string sub2(filename, pos);
//		cout << sub2 << endl;
//
//		string sub3 = filename.substr(pos);
//		cout << sub3 << endl;
//	}
//	return 0;
//}

int main()
{
	string s1 = "http://www.cplusplus.com/reference";
	cout << GetDomain(s1) << endl;
	cout << GetProtocol(s1) << endl;
	return 0;
}