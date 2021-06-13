#include <iostream>
using namespace std;


//���ͱ��
//����ģ�����T��typename��class����
template<class T>
//template<typename T>
//����ģ��
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
//һ���Ե�
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
//	//ָ������
//	cout << add<int>(a, c) << endl;
//	cout << add<double>(b, d) << endl;
//	return 0;
//}

//ģ����ã����ֳ�ƥ�亯���ľ������ã����Բ�ȥʵ����ģ��
//�и�ƥ��ģ�����ƥ����������ʵ�


//struct place
//{
//	int i;
//};
//typedef struct place s;
//��ģ��
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

//ģ�岻֧�ַ������-��������.h��������.cpp
//���鶨����һ��

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
