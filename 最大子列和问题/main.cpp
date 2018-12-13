#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	int a[100000] = { 0 };
	int maxSum = 0, tempSum = 0;
	int start = 0, end = num - 1, addNum = 0;
	for (int i = 0; i < num; ++i)
	{
		cin >> a[i];
		tempSum += a[i];
		++addNum; //统计每一次tempSum加了几次
		if (tempSum >= maxSum)
		{
			if (tempSum != maxSum || (tempSum == 0 && maxSum == 0))
			{
				maxSum = tempSum;
				end = i;
				start = end - addNum + 1;
			}
		}
		else if(tempSum < 0)
		{
			addNum = 0;
			tempSum = 0;
		}
	}
	cout << maxSum << " " << a[start] << " " << a[end] << endl;
	return 0;
}