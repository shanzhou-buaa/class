#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main()
//{
//	//�����Զ����� 
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
//	//����
//  //1.ѭ��
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
//	string::iterator it = s1.begin();//�ɶ���д
//	//2.��������������
//	//[begin(), end())
//	//end()�������һ��λ�õ���һ��λ�ã��ַ���ʱ��'\0'
//	//C++�еĵ�����һ�㶼������ҿ�
//	//iterator������ָ���һ������
//	//string��vector֧��[]����list��map�Ȳ�֧��
//	//��������ͳһ�ķ�ʽ
//	while (it != s1.end())
//	{
//		*it += 2;
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//���������
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
//	string::const_iterator it = s1.begin();//ֻ��
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}


//3.��Χfor
//int main()
//{
//	string s1 = "123456";
//	//��s1�ڵ����ݸ�ֵ��e���Զ��жϽ���
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
//	//insert�������ã���Ϊͷ�����м��������ҪŲ������
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