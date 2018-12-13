#include<stdio.h>  
#include<iostream>
# define N 9

void GreadyActivitySelector(int *s, int *f, int *A, int n);
void RecursiveActivitySelector(int *s, int *f, int *A, int i, int n, int k);

void main()
{
	int s[N] = { 2,2,3,4,6,7,9,10,13 };//开始时间  
	int f[N] = { 3,4,5,7,8,11,12,15,17 };//结束时间  
	int A[N] = { 0 };//初始化  
	int n = N;
	GreadyActivitySelector(s, f, A, n);//迭代版本  
									   //  RecursiveActivitySelector(s,f,A,0,n,0);//递归版本  
	for (int i = 0; i<n; i++)
		printf("%d ", A[i]);//被选择的活动   

	system("pause");
}

/****************************************************\
函数功能：选择最佳的活动安排
输入：    各个活动的起始时间和结束时间、待存储被选择活动的数组A、活动个数
输出：    无
\****************************************************/

void GreadyActivitySelector(int *s, int *f, int *A, int n)//迭代版本  
{
	A[0] = 1;
	int i = 0;
	int j = 1;
	for (int m = 1; m<n; m++)
	{
		if (s[m] >= f[i])//开始时间大于上个活动的结束时间  
		{
			i = m;
			A[j] = m + 1;//注意下标与第几位差一  
			j++;
		}
	}
}

/****************************************************\
函数功能：选择最佳的活动安排
输入：    各个活动的起始时间和结束时间、待存储被选择活动的数组A、i,n表示子问题的活动，活动个数
输出：    无
\****************************************************/
void RecursiveActivitySelector(int *s, int *f, int *A, int i, int n, int k)//递归版本  
{
	int j = k;
	int m = i;

	while ((m<n) && (s[m]<f[i]) && (m != 0))//找到结束时间大于上个活动开始时间的活动  
		m = m + 1;
	if (m<n)
	{
		A[j] = m + 1;//将被选择的活动存储起来  

		j++;
		RecursiveActivitySelector(s, f, A, m + 1, n, j);
	}


}