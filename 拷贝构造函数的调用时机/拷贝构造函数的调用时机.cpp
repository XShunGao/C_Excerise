#include "Person.h"

void test01()
{
	//1.ʹ���Ѿ������õĶ����ʼ����һ������
	Person p1;	//����Ĭ�ϳ�ʼ������
	Person p2(p1);  // ���Ե��ÿ������캯��
	Person p3 = Person(p2 ); //��ʾ���ÿ������캯��

}


void doWork(Person p)
{

}

void test02()
{
	//2.��ֵ���ݵķ�ʽ���������Ĳ�����ֵ
	Person p1;
	doWork(p1);
}

Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	//3.��ֵ�ķ�ʽ���ؾֲ�����
	Person p2 = doWork2();
}

/*
	release�±��������Ż�
	void doWork2(Person &p)
	{
	}
	void test03()
	{
		Person p;
		doWork2(p);
	}

*/

int main()
{
	//test02();
	test03();
	system("pause");
	return 0;
}