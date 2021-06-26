#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <assert.h>

#include <iostream>
using namespace std;

//支持增删查改的string类
namespace yh
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
			_capacity = _size;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t i)
		{
			assert(i < _size && i >= 0);
			return _str[i];
		}

		const char& operator[](size_t i) const
		{
			assert(i < _size && i >= 0);
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* temp = new char[n + 1];//多开一个给\0
				if (temp == nullptr)
				{
					cout << "reserve fail" << endl;
					return;
				}
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = n;
			}
		}

		void push_back(const char ch)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = (_capacity == 0) ? 4 : 2 * _capacity;
				reserve(newcapacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				//不能按2倍增，因为增2倍也不一定够
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(const char ch)
		{
			this->push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		void insert(size_t pos, const char* str)
		{

		}
	private:
		char* _str;
		size_t _size;//当前字符串内的有效个数
		size_t _capacity;//能存储的有效字符个数，不包括\0

		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
			out << s[i];
		return out;
	}
}

void test1();
void test2();

int main()
{
	test1();
	test2();
	return 0;
}

void test1()
{
	yh::string s1;
	yh::string s2("hello");
	cout << s1 << endl << s2 << endl;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	for (size_t i = 0; i < s2.size(); i++)
	{
		s2[i] += 1;
		cout << s2[i];
	}
	cout << endl;

	yh::string::iterator it2 = s2.begin();
	while (it2 != s2.end())
	{
		*it2 -= 1;
		cout << *it2;
		it2++;
	}
	cout << endl;

	//范围for是由迭代器支持的，这段代码最终会被替换成迭代器 
	for (auto c : s2)
		cout << c;
	cout << endl;
}

void test2()
{
	yh::string s1("hello");
	cout << s1 << endl;

	//s1.push_back(' ');
	//cout << s1 << endl;

	//s1.push_back('w');
	//cout << s1 << endl;

	//s1.push_back('o');
	//cout << s1 << endl;

	//s1.append("rld");
	//cout << s1 << endl;

	s1 += ' ';
	s1 += 'w';
	cout << s1 << endl;

	s1 += "orld";
	cout << s1 << endl;
}