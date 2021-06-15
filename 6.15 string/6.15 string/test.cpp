#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main()
//{
//	//析构自动调用 
//	std::string s1 = "";
//	string s2("hello world");
//	string s3(s2);
//	string s4 = "hello world";
//	string s5(s4, 0, 5);
//
//
//	printf("s1:%s\n", s1.c_str());
//	printf("s2:%s\n", s2.c_str());
//	printf("s3:%s\n", s3.c_str());
//	printf("s4:%s\n", s4.c_str());
//	printf("s5:");
//	cout << s5 << endl;
//
//	string s6 = "yes";
//	if (s6 > s2)
//		printf(">\n");
//
//	return 0;
//}

//int main()
//{
//	string s1 = "";
//	string s2("hello world");
//	
//	//遍历
//  //1.循环
//	for (size_t i = 0; i < s2.size(); i++)
//	{
//		s2[i] = 'x';
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	string s1 = "123456";
//	string::iterator it = s1.begin();//可读可写
//	//2.迭代器，闭区间
//	//[begin(), end())
//	//end()返回最后一个位置的下一个位置，字符串时是'\0'
//	//C++中的迭代器一般都是左闭右开
//	//iterator是类似指针的一个东西
//	//string，vector支持[]，但list，map等不支持
//	//迭代器是统一的方式
//	while (it != s1.end())
//	{
//		*it += 2;
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//反向迭代器
//	//string s2 = "123456789";
//	//string::reverse_iterator rit = s2.rbegin();
//	//while (rit != s2.rend())
//	//{
//	//	cout << *rit << " ";
//	//	++rit;
//	//}
//	//cout << endl;
//	return 0;
//}


//int main()
//{
//	const string s1 = "abcd";
//	string::const_iterator it = s1.begin();//只读
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}


//3.范围for
//int main()
//{
//	string s1 = "123456";
//	//把s1内的数据赋值给e，自动判断结束
//	for (auto& c : s1)
//	{
//		c += 1;
//		cout << c << " ";
//	}
//	cout << endl;
//
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	for (int& i : v)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	string s1;
//	s1.push_back('h');
//	s1.push_back('e');
//	s1.push_back('l');
//	s1.push_back('l');
//	s1.push_back('o');
//
//	cout << s1 << endl;
//	string s2 = " ";
//	s1.append(s2);
//	cout << s1 << endl;
//
//	string s3 = "world";
//	s1.append(s3.begin(), s3.end());
//	cout << s1 << endl;
//
//	s1 += '!';
//	cout << s1 << endl;
//
//	s1 += "!!!";
//	cout << s1 << endl;
//	s1 += s3;
//	cout << s1 << endl;
//
//	//insert尽量少用，因为头部或中间插入数据要挪动数据
//	s1.insert(0, "5");
//	cout << s1 << endl;
//
//	s1.insert(4, "678");
//	cout << s1 << endl;
//
//	s1.erase(0, 5);
//	cout << s1 << endl;
//
//	s1.erase(4, 6);
//	cout << s1 << endl;
//
//	s1.erase(1);
//	cout << s1 << endl;
//
//	s1.erase();
//	cout << s1 << endl;
//
//	return 0;
//}