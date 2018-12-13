#include<iostream>
#include<vector>

using namespace std;

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
			reVec.push_back(-1);
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

int main()
{
	const int n = 10;
	int a[n] = { 0,1,2,3,4,6,7,8,9,10 };
	vector<int> v;
	v = binarySearchV(a, 10, 5);
	cout << v[0] << " "<< v[1] <<endl;
	v = binarySearchV(a, 10, 6);
	cout << v[0] << " " << v[1] << endl;
	system("pause");
	return 0;
}