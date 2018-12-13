#pragma once
#include <iostream>

using namespace std;

class Person
{
public:
	//默认构造函数
	Person()
	{
		cout << "默认构造函数" << endl;
	}

	~Person()
	{
		cout << "调用析构函数" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "有参构造函数" << endl;
	}

	Person(const Person &p)
	{
		m_age = p.m_age;
		cout << "拷贝构造函数" << endl;
	}

private:
	int m_age;

};