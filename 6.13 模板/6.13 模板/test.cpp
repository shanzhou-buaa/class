#include <iostream>
using namespace std;


//泛型编程
//定义模板参数T用typename和class都行
template<class T>
//template<typename T>
//函数模板
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
//一次性的
//template<class T>
//T add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 5.1, d = 10.2;
//	
//	//指定类型
//	cout << add<int>(a, c) << endl;
//	cout << add<double>(b, d) << endl;
//	return 0;
//}

//模板调用，有现成匹配函数的就优先用，绝对不去实例化模板
//有更匹配的，优先匹配类型最合适的


//struct place
//{
//	int i;
//};
//typedef struct place s;
//类模板
template<class t>
class SeqList
{
public:
	SeqList()
		:_a(nullptr)
		, _size(0)
		, _capacity(0)
	{}

	void push_back(int x)
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			t* tmp = new t[newcapacity];
			if (_a != nullptr)
			{
				memcpy(tmp, _a, sizeof(t)*_size);
				delete[] _a;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_size++] = x;
	}

	~SeqList()
	{
		delete[] _a;
		_a = nullptr;
		_size = 0;
		_capacity = 0;
	}

	t& operator[](size_t pos)
	{
		assert(pos < size);
		return _a[pos];
	}

	size_t size()
	{
		return _size;
	}
private:
	t* _a;
	int _size;
	int _capacity;
};

//模板不支持分离编译-》声明在.h，定义在.cpp
//建议定义在一起

int main()
{
	SeqList<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << v1[3] << endl;

	SeqList<double> v2;

	return 0;
}
