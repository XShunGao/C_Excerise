#include<stdio.h>  
#include<iostream>
# define N 9

void GreadyActivitySelector(int *s, int *f, int *A, int n);
void RecursiveActivitySelector(int *s, int *f, int *A, int i, int n, int k);

void main()
{
	int s[N] = { 2,2,3,4,6,7,9,10,13 };//��ʼʱ��  
	int f[N] = { 3,4,5,7,8,11,12,15,17 };//����ʱ��  
	int A[N] = { 0 };//��ʼ��  
	int n = N;
	GreadyActivitySelector(s, f, A, n);//�����汾  
									   //  RecursiveActivitySelector(s,f,A,0,n,0);//�ݹ�汾  
	for (int i = 0; i<n; i++)
		printf("%d ", A[i]);//��ѡ��Ļ   

	system("pause");
}

/****************************************************\
�������ܣ�ѡ����ѵĻ����
���룺    ���������ʼʱ��ͽ���ʱ�䡢���洢��ѡ��������A�������
�����    ��
\****************************************************/

void GreadyActivitySelector(int *s, int *f, int *A, int n)//�����汾  
{
	A[0] = 1;
	int i = 0;
	int j = 1;
	for (int m = 1; m<n; m++)
	{
		if (s[m] >= f[i])//��ʼʱ������ϸ���Ľ���ʱ��  
		{
			i = m;
			A[j] = m + 1;//ע���±���ڼ�λ��һ  
			j++;
		}
	}
}

/****************************************************\
�������ܣ�ѡ����ѵĻ����
���룺    ���������ʼʱ��ͽ���ʱ�䡢���洢��ѡ��������A��i,n��ʾ������Ļ�������
�����    ��
\****************************************************/
void RecursiveActivitySelector(int *s, int *f, int *A, int i, int n, int k)//�ݹ�汾  
{
	int j = k;
	int m = i;

	while ((m<n) && (s[m]<f[i]) && (m != 0))//�ҵ�����ʱ������ϸ����ʼʱ��Ļ  
		m = m + 1;
	if (m<n)
	{
		A[j] = m + 1;//����ѡ��Ļ�洢����  

		j++;
		RecursiveActivitySelector(s, f, A, m + 1, n, j);
	}


}