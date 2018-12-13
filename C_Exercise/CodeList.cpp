#include <iostream>
#include <cmath>
#include <Windows.h>
#include <cstdlib>  // 随机数函数
#include <ctime>
#include <vector>

using namespace std;
int Code3_1();
int Code3_9();
int sequenceSearch(int a[], int n, int c);
int sequenceSearch1(int a[], int n, int c);
int binarySearch(int a[], int n, int c);
void test_memory();
template<class T> void Swap(T &a, T &b);
int Partition(int a[], int p, int r);
template<class T> int Partition1(T a[], int p, int r);
template<class T> int Partition3m(T a[], int p, int r);
template<class T> void QuickSort(T a[], int start, int end);
template<class T> void QuickSort3M(T a[], int start, int end);
vector <int> binarySearchV(int a[], int n, int c);

int main()
{
	//Code3_9();
	 const int n = 10;
	 int a[n] = { 0,1,2,3,4,6,7,8,9,10 };
	 int b[6] = { 6,7,5,2,5,8 };
	 int c[8] = { 2,8,7,1,3,5,6,8 };
	 int d[8] = { 2,8,7,1,3,5,6,8 };
	//int c = 5;
	//int i = sequenceSearch1(a, n, c);
	//int k = binarySearch(a, n, c);
	/*cout << "i = " << i << endl;
	cout << "k = " << k << endl;*/

	 /*快排*/
	 /*
	 QuickSort(c, 0, 7);
	 for (int i = 0; i <= 7; ++i)
	 {
		 cout << "QuickSort:" << c[i] << endl;
	 }
	 QuickSort3M(d, 0, 7);
	 for (int i = 0; i <= 7; ++i)
	 {
		 cout << "QuickSort3M:" << d[i] << endl;
	 }
	 */

	 //二分查找，返回vector
	 vector<int> v;
	 v= binarySearchV(a, 10, 5);
	 system("pause");
	 return 0;
}

//
//银行利息程序版本1
//
int Code3_1()
{
	const double oneYearRate = 0.025, twoYearRate = 0.028;
	double balance, interest;
	int type, startDate, endDate;
	L1:
		cout << "请输入存款类型（1：一年期，2：两年期，0：活期）：";
	cin >> type;
	cout << "请输入存款金额：";
	cin >> balance;
	input:
	{
		cout << "请输入起始日期：";
		cin >> startDate;
		cout << "请输入结束日期：";
		cin >> endDate;
	}
	if (startDate > endDate)
	{
		cout << "起始日期必须小于结束日期，请重新输入:" << endl;
		goto input;
	}

	
	//double rate = (type == 1) ? oneYearRate : twoYearRate;

	double rate;
	switch (type)
	{
	case 0:  rate = twoYearRate - oneYearRate; break;
	case 1:  rate = oneYearRate; break;
	case 2:  rate = twoYearRate; break;
	default: goto L1; break;
	}
	interest = pow(1 + rate, endDate - startDate)*balance - balance;
	cout << balance << "元存" << endDate - startDate << "年，共得" 
		<< interest << "元利息。" << endl;

	return 0;
}

//随机出题函数
int Code3_9()
{
	int num1, num2, op, result1, result2; //num1.num2操作数，op运算符，result结果
	srand(time(NULL));
	num1 = rand() * 10 / (RAND_MAX + 1);   //生成运算数
	num2 = rand() * 10 / (RAND_MAX + 1);
	op = rand() * 4 / (RAND_MAX + 1);      // 生成运算符
	switch (op) 
	{
	case 0:cout << num1 << "+" << num2 << "=" << "?" << endl;
		   cin >> result1;
		   if (num1 + num2 == result1) cout << "Right！" << endl;
		   else cout << "False" << endl;
		   break;

	case 1:cout << num1 << "-" << num2 << "=?" << endl;
		   cin >> result1;
		   if (num1 - num2 == result1) cout << "Right!" << endl;
		   else cout << "False!" << endl;
		   break;
	case 2:cout << num1 << "*" << num2 << "=?" << endl;
		cin >> result1;
		if (num1*num2 == result1) cout << "Right!" << endl;
		else cout << "False!" << endl;
		break;
	case 3:cout << num1 << "/" << num2 << "=?"<<endl;
		cin >> result1 ;
		cout << "余数为：" << endl;
		cin >> result2;

		if ((num1 / num2 == result1) && (num1%num2 == result2)) cout << "right" << endl;
		else cout << "false" << endl;
		break;
	}

	return 0;
}

//顺序查找 算法设计例题1-1
int sequenceSearch(int a[], int n, int c)
{
	for (int i = 0; i <= n; ++i)
	{
		if (a[i] == c && i < n)
			return i;
		else if (i == n)
			return 0;
	}
	return -1;
}

int sequenceSearch1(int a[], int n, int c)
{
	int i = 0;
	while (a[i] < c && i < n)
	{
		++i;
	}
	if (a[i] = c)
		return i;
	else
		return 0;

	return -1;
}

//
//二分查找 非递归
//
int binarySearch(int a[], int n, int c)
{
	//需要找到循环终止条件
	int start = 0, end = n - 1;
	while (start < end)
	{
		int mid = (start + end)/ 2;
		if (a[mid] == c)
			return mid;
		if (a[mid] < c)
		{
			//在后半查找
			start = mid + 1;
		}
		else
		{
			//在前半查找
			end = mid - 1;
		}
	}
	return -1;
}

//
//搜索元素x不在数组中时，返回小于x的最大元素位置i 和大于x的最小元素位置 j
//设置返回值为vector
//
vector <int> binarySearchV(int a[], int n, int c)
{
	vector<int> reVec;
	int start = 0, end = n - 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (a[mid] == c)
		{
			reVec.push_back(mid);
			return reVec;
		}
		if (a[mid] < c)
		{
			//在后半查找
			start = mid + 1;
		}
		else
		{
			//在前半查找
			end = mid - 1;
		}
	}
	reVec.push_back(start - 1);
	reVec.push_back(start);
	return reVec;
}

//
//二分查找，非递归版本
//
int binarySearch1(int a[], int n, int c)
{
	int start = 0, end = n - 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (a[mid] == c)
			return mid;
		if (a[mid] < c)
		{
			//在后半查找
			start = mid + 1;
		}
		else
		{
			//在前半查找
			end = mid - 1;
		}
	}
	return start;
}

int binarySearch_digui(int a[], int start, int end, int c)
{
	int a_size = (end - start + 1);
	int mid = a_size / 2;
	if (a[mid] == c)
		return mid;
	if (a[mid] < c)
	{
		//在后半查找
		binarySearch_digui(a, mid + 1, end, c);
	}
	else
	{
		//在前半查找
		binarySearch_digui(a, start, mid - 1, c);
	}
	return -1;
}

void test_memory()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "创建一个动态数组" << endl;
		int *pia = new int[7] {0, 1, 2, 3, 4, 5, 6};


		cout << "删除动态数组" << endl;
		delete[] pia;
	}
	;
//	int *pia = new int[] {0, 1, 2, 3, 4, 5, 6};



}

//
//交换两个值
//
template<class T>
void Swap(T &a, T &b)
{
	T temp = 0;
	temp = a;
	a = b;
	b = temp;
}

//
//将数组分为两个部分,有问题,已解决，key取第一个元素时，要先从后面开始扫描
//
int Partition(int a[], int p, int r)
{
	int low = p, high = r + 1;
	int key = a[p];
	while (true)
	{
		do
		{
			--high;
		} while (a[high] > key);
		do
		{
			++low;
		} while (a[low] < key && low < r);
		if (low < high)
		{
			Swap(a[low], a[high]);
		}
		else
		{   
			Swap(a[p], a[high]);
			return high;
		}		
	}
	return -1;
}

template<class T>
int Partition1(T a[], int p, int r)
{
	int i = p ;
	int key = a[r];
	for (int j = p; j < r; ++j)
	{
		if (a[j] < a[r])
		{
			Swap(a[i], a[j]);
			++i;
		}
	}
	Swap(a[i], a[r]);
	return i;
}

//
//三者取中法
//
template<class T>
int Partition3m(T a[], int p, int r)
{
	//三者取中，把中间的数放到数组第一个
	if (a[p] > a[r])
	{
		Swap(a[p], a[r]);
	}
	if (a[p] < a[(p + r) / 2])
	{
		Swap(a[p], a[(p + r) / 2]);
	}
	
	//跟之前的一样
	int i = p;
	int key = a[r];
	for (int j = p; j < r; ++j)
	{
		if (a[j] < a[r])
		{
			Swap(a[i], a[j]);
			++i;
		}
	}
	Swap(a[i], a[r]);
	return i;
}

template<class T>
void QuickSort(T a[], int start, int end)
{
	if (start < end)
	{
		int q = Partition(a, start, end);
		QuickSort(a, start, (q - 1));
		QuickSort(a, q + 1, end);
	}
}

template<class T> 
void QuickSort3M(T a[], int start, int end)
{
	if (start < end)
	{
		int q = Partition3m(a, start, end);
		QuickSort3M(a, start, (q - 1));
		QuickSort3M(a, (q + 1), end);
	}
}
