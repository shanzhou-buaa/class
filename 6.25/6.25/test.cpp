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
		//	:_str(new char[strlen(str) + 1])//���뱣��\0
		//{
		//	strcpy(_str, str);
		//}

		//��һ���ַ���
		string(char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//��һ��string����
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//s1 = s3;
		string& operator=(const string& s)
		{
			if (&s != this)//��ֹ�Լ����Լ���ֵ
			{
				//��һ����ʱ�ռ�
				char* temp = new char[strlen(s._str) + 1];
				//��s�Ŀ�������ʱ�ռ���
				strcpy(temp, s._str);
				//�ͷ�this��_str
				delete[] _str;
				//this��_strָ����ʱ�ռ�
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
		s1[i] += 1;//�ַ������ڳ�����ʱ�����޸�
		cout << s1[i] << " ";
	}
	cout << endl;

	yh::string s2;
	for (size_t i = 0; i < s2.size(); i++)
	{
		s2[i] += 1;//�ַ������ڳ�����ʱ�����޸�
		cout << s2[i] << " ";
	}
	cout << endl;
}