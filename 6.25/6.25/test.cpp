#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>

namespace yh
{
	class string
	{
	public:
		//string()
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';
		//}

		//string(char* str)
		//	:_str(new char[strlen(str) + 1])//必须保留\0
		//{
		//	strcpy(_str, str);
		//}

		//传一个字符串
		string(char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//传一个string变量
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//s1 = s3;
		string& operator=(const string& s)
		{
			if (&s != this)//防止自己给自己赋值
			{
				//开一个临时空间
				char* temp = new char[strlen(s._str) + 1];
				//把s的拷贝到临时空间里
				strcpy(temp, s._str);
				//释放this的_str
				delete[] _str;
				//this的_str指向临时空间
				_str = temp;
			}
			return *this;
		} 

		size_t size()
		{
			return strlen(_str);
		}

		const char* c_str()
		{
			return _str;
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
}

void test1();
void test2();

int main()
{
	//test1();
	test2();
	return 0;
}

void test2()
{
	yh::string s1("hello");
	yh::string s2(s1);

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	yh::string s3("world");
	s1 = s3;
	cout << s1.c_str() << endl;
	cout << s3.c_str() << endl;
}

void test1()
{
	yh::string s1 = "hello";
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i] += 1;//字符串存在常量区时不能修改
		cout << s1[i] << " ";
	}
	cout << endl;

	yh::string s2;
	for (size_t i = 0; i < s2.size(); i++)
	{
		s2[i] += 1;//字符串存在常量区时不能修改
		cout << s2[i] << " ";
	}
	cout << endl;
}