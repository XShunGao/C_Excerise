#pragma once
#include <iostream>

using namespace std;

class Person
{
public:
	//Ĭ�Ϲ��캯��
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	~Person()
	{
		cout << "������������" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "�вι��캯��" << endl;
	}

	Person(const Person &p)
	{
		m_age = p.m_age;
		cout << "�������캯��" << endl;
	}

private:
	int m_age;

};