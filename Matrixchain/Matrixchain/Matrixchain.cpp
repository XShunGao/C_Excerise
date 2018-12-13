#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


void  Matrixchain(int * p, int n, int m[][100], int s[][100])
{
	int i, j, k, r, t;
	for (i = 1; i <= n; i++) m[i][i] = 0;
	for (r = 2; r <= n; r++)
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (k = i + 1; k<j; k++)
			{
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t<m[i][j])
				{
					m[i][j] = t; s[i][j] = k;
				}
			}
		}
}


void Traceback(int i, int j, int s[][100])
{
	if (i == j) {
		cout << "A" << i;
		return;
	}
	cout << "(";
	Traceback(i, s[i][j], s);
	cout << ",";
	Traceback(s[i][j] + 1, j, s);
	cout << ")";
}

int main()
{
	int    m[100][100], s[100][100];
	int total = 8;
	int size[9] = { 10,100,5,50,30,20,60,45,50 };
	Matrixchain(size, total, m, s);
	cout << "该" << total << "个矩阵的最优计算次序：" << endl;
	Traceback(1, total, s);
	cout << endl;
	system("pause");
	return 0;
}