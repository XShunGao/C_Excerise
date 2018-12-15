#include<iostream>

using namespace std;

//
//��������ֵ
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
//�������Ϊ��������,������,�ѽ����keyȡ��һ��Ԫ��ʱ��Ҫ�ȴӺ��濪ʼɨ��
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

//
//����ȡ�з�
//
template<class T>
int Partition3m(T a[], int p, int r)
{
	//����ȡ�У����м�����ŵ������һ��
	if (a[p] > a[r])
	{
		Swap(a[p], a[r]);
	}
	if (a[p] < a[(p + r) / 2])
	{
		Swap(a[p], a[(p + r) / 2]);
	}

	//��֮ǰ��һ��
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

int main()
{
	int c[8] = { 2,8,7,1,3,5,6,8 };
	int d[8] = { 2,8,7,1,3,5,6,8 };
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
	system("pause");
	return 0;
}