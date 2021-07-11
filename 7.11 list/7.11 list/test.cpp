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
	struct __list_node
	{
		__list_node(const T& x = T())
			:_prev(nullptr)
			, _next(nullptr)
			, _data(x)
		{}

		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;
	};
	
	template<class T>
	class __list_iterator
	{
		typedef __list_node<T> Node;
	public:
		__list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		//++it
		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//it++
		__list_iterator<T>& operator++(int)
		{
			__list_iterator<T> temp(*this);
			_node = _node->_next;
			return temp;
		}

		//--it 
		__list_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//it--
		__list_iterator<T>& operator--(int)
		{
			__list_iterator<T> temp(*this);
			_node = _node->_prev;
			return temp;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}

	private:
		Node* _node;
	};

	//双向带头循环链表
	template<class T>
	class List
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T> Iterator;
	public:
		List()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newNode = new Node(x);

			tail->_next = newNode;
			_head->_prev = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
		}
			
		Iterator begin()
		{
			return Iterator(_head->_next);
		}

		//最后一个结点的下一个位置
		Iterator end()
		{
			return Iterator(_head);
		}

		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//删掉除了_head以外的结点
		void clear()
		{
			Iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

	private:
		Node* _head;
	};
}

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	yh::List<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	yh::__list_iterator<int> it = lt.begin();
	//yh::__list_iterator<int> it(lt.begin());

	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
}