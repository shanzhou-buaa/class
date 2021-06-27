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
				reserve(_size + len);//不能按2倍增，因为增2倍也不一定够
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

		string& insert(size_t pos, const char ch)
		{
			assert(pos >= 0 && pos < _size);
			if (_size == _capacity)
			{
				size_t newcapacity = (_capacity == 0) ? 4 : 2 * _capacity;
				reserve(newcapacity);
			}
			size_t begin = pos;
			size_t end = _size;
			//从\0开始每个字符都往后挪一位
			for (size_t i = end; i >= begin; i--)
				_str[i + 1] = _str[i];
			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos >= 0 && pos < _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);

			size_t begin = pos;
			size_t end = _size;
			for (size_t i = end; i >= begin; i--)
				_str[i + len] = _str[i];
			/*for (size_t i = 0; i < len; i++)
				_str[pos + i] = str[i];*/
			strncpy(_str + pos, str, len);
			_size += len;
		
			return *this;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			//n >= _size
			else
			{
				if (n > _capacity)
					reserve(n);
				size_t i;
				for (i = _size; i < n; i++)
					_str[i] = ch;
				_str[i] = '\0';
				_size = n;
			}
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < size());

			if (pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i;
				//注意结束条件，把\0也往前挪
				for (i = pos; i <= size() - len; i++)
					_str[i] = _str[i + len];
				_size -= len;
			}

			return *this;
		}

		size_t find(const char ch, size_t pos = 0)
		{
			size_t i;
			for (i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			char* p = strstr(_str, str);
			if (p == nullptr)
				return npos;
			else
				return p - _str;
		}

		bool operator<(const string& s)
		{
			int ret = strcmp(this->_str, s._str);
			return ret < 0;
		}

		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
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

	istream& operator>>(istream& in, string& s)
	{
		while (1)
		{
			char ch = in.get();
			//去掉空格的判断条件就是getline
			if (ch == ' ' || ch == '\n')
				break;
			else
				s += ch;
		}
	
		return in;
	}
}

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
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

void test3()
{
	yh::string s1("hllo");
	s1.insert(1, 'e');
	cout << s1 << endl;

	yh::string s2("ad");
	s2.insert(1, "bc");
	cout << s2 << endl;
}

void test4()
{
	yh::string s1("abcde");
	s1.resize(2);
	cout << s1 << endl;

	yh::string s2("abcde");
	s2.resize(6, 'x');
	cout << s2 << endl;

	yh::string s3("abcde");
	s3.resize(17, '1');
	cout << s3 << endl;

	s3.erase(0, 2);
	cout << s3 << endl;

	s2.erase(2, 3);
	cout << s2 << endl;

	s1.erase(0, 500);
	cout << s1 << endl;
}

void test5()
{
	string s1("abcdabcdef");
	cout << s1.find("cde") << endl;
	cout << s1.find("zz") << endl;
}

void test6()
{
	yh::string s1;
	cin >> s1;
	cout << s1;
}