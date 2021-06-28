#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <iostream>
using namespace std;

namespace yh
{
	class string{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//深拷贝的传统写法
		/*string(const string& s)
			:_str(new char[strlen(s._str)  + 1])
		{
			strcpy(_str, s._str);
		}*/

		//深拷贝的现代写法
		string(const string& s)
			:_str(nullptr)
		{
			string temp(s._str);
			swap(_str, temp._str);
		}
		
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
			}

			return *this;
		}*/

		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		size_t size()
		{
			return strlen(_str);
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

int main()
{
	yh::string s1("hello");
	yh::string s2(s1);
	yh::string s3 = s1;
	for (size_t i = 0; i < s2.size(); i++)
		cout << s2[i];
	cout << endl;
	cout << endl;
	
	for (size_t i = 0; i < s3.size(); i++)
		cout << s3[i];
	cout << endl;
	cout << endl;

	return 0;
}