#include<iostream>

using namespace std;

void merge(int *a, int low, int mid, int high)
{
	int i = low, j = mid + 1, p = 0;
	int *r = new int[high - low + 1];
	while (i <= mid && j <= high)
	{
		r[p++] = (a[i] <= a[j]) ? a[i++] : a[j++];
	}
	while (i <= mid)
	{
		r[p++] = a[i++];
	}
	while (j <= high)
	{
		r[p++] = a[j++];
	}
	for (p = 0, i = low; i <= high; p++, i++)
	{
		a[i] = r[p];
	}
	delete[]r;
}

void MSort(int *a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MSort(a, low, mid);
		MSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

void MergeSort(int *a, int n)
{
	MSort(a, 0, n - 1);
}

int main()
{
	int a[] = { 0,1,54,2,3,65,4,15,6,32,8,11,9,15,66,88 };
	int n = sizeof(a) / sizeof(int);
	MergeSort(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
	
}