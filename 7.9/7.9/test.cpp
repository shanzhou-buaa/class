#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

namespace yh
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		typedef const T* constIterator;

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _EndOfStorage(nullptr)
		{}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t Size = size();
				T* tmp = new T[n];
				if (_start != nullptr)
				{
					for (size_t i = 0; i < Size; i++)
						tmp[i] = _start[i];
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + Size;
				_EndOfStorage = _start + n;
			}
		}

		void PushBack(const T& x)
		{
			if (_finish == _EndOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			_finish++;
		}
		
		Iterator begin()
		{
			return _start;
		}

		Iterator end()
		{
			return _finish;
		}

		constIterator begin() const
		{
			return _start;
		}

		constIterator end() const
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _EndOfStorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}

		void PopBack()
		{
			assert(size() > 0);
			--_finish;
		}

		void Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);

			if (_finish == _EndOfStorage)
			{
				//pos和_start之间的距离
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//_start已经到新的空间，但pos还在原来的位置，迭代器失效
				pos = n + _start;
			}
			Iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			_finish++;
		}

		Iterator erase(Iterator pos)
		{
			assert(pos < _finish);

			Iterator cur = pos;
			for (; cur < _finish - 1; cur++)
			{
				*cur = *(cur + 1);
			}
			_finish--;
			return pos;
		}
		
		//							T类型的缺省值
		void resize(size_t n, const T& val = T())
		{
			//size_t _size = size();
			//size_t _capacity = capacity();
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
					reserve(n);
				//memxxx按字节处理
				//除了0，其它任何值都达不到初始化的目的
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		~Vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_EndOfStorage = nullptr;
		}
		
		//Vector(const Vector<T>& v)
		//{
		//	_start = new T[v.capacity()];
		//	_finish = _start;
		//	_EndOfStorage = _start + v.capacity();

		//	for (size_t i = 0; i < v.size(); i++)
		//	{
		//		*_finish = v[i];
		//		_finish++;
		//	}
		//}

		Vector(const Vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _EndOfStorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
				PushBack(e);
		}

		//Vector<T>& operator=(const Vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		delete[] _start;
		//		_start = new T[v.capacity()];
		//		memcpy(_start, v._start, sizeof(T)* v.size());
		//	}

		//	return *this;
		//}

		//v2(v1)
		//v是v1的拷贝构造
		Vector<T>& operator=(Vector<T> v)
		{
			swap(v);

			return *this;
		}

		void swap(Vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_EndOfStorage, v._EndOfStorage);
		}

	private:
		//_start + size() = _finish
		//_start + capacity() = _EndOfStorage
		Iterator _start;
		Iterator _finish;
		Iterator _EndOfStorage;
	};

	void printVector(const Vector<int>& v)
		{
			Vector<int>::constIterator it = v.begin();
			while (it != v.end())
			{
				//*it += 1;
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}
}

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}

void test1()
{
	yh::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);

	yh::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	printVector(v);
}

void test2()
{
	yh::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);

	//v.erase(v.begin());
	//yh::printVector(v);

	//v.erase(v.end());
	//yh::printVector(v);

	yh::Vector<int>::Iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			it++;
	}
	yh::printVector(v);
}

void test3()
{
	yh::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	
	v.resize(4);
	yh::printVector(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;
	
	v.resize(7, 7);
	yh::printVector(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(10, 10);
	yh::printVector(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;
}

void test4()
{
	yh::Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	yh::Vector<int> v2(v1);

	yh::printVector(v1);
	yh::printVector(v2);

	yh::Vector<int> v3;
	v3.PushBack(10);
	v3.PushBack(20);
	v3.PushBack(30);
	v3.PushBack(40);

	v1 = v3;
	yh::printVector(v1);
}

void test5()
{
	yh::Vector<string> v;
	v.PushBack("111");
	v.PushBack("222");
	v.PushBack("333");
	v.PushBack("444");
	v.PushBack("555");
	v.PushBack("666");


	for (auto e : v)
		cout << e << endl;

}