#include "Person.h"

void test01()
{
	//1.使用已经创建好的对象初始化另一个对象
	Person p1;	//调用默认初始化参数
	Person p2(p1);  // 隐试调用拷贝构造函数
	Person p3 = Person(p2 ); //显示调用拷贝构造函数

}


void doWork(Person p)
{

}

void test02()
{
	//2.以值传递的方式，给函数的参数传值
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
	//3.以值的方式返回局部对象
	Person p2 = doWork2();
}

/*
	release下编译器做优化
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