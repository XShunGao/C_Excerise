#include "ChessBoard.h"

using namespace std;

//   Chess::Chess(int **a, int dr, int dc, int tr, int tc, int size)
Chess::Chess(int (*a)[N], int dr, int dc, int tr, int tc, int size)
{
	
	if (size == 1)
		return;
	if (size > 1)
	{
 		s_size = 0.5 * size;
		if (dr <= (tr + s_size - 1) && dc <= (tc + s_size - 1))
		{
			a[tr + s_size - 1][tc + s_size] = t;
			a[tr + s_size][tc + s_size] = t;
			a[tr + s_size][tc + s_size - 1] = t;
			++t;
			Chess(a, dr, dc, tr, tc, s_size);
			Chess(a, tr + s_size - 1, tc + s_size, tr, tc + s_size, s_size);
			Chess(a, tr + s_size, tc + s_size, tr + s_size, tc + s_size, s_size);
			Chess(a, tr + s_size, tc + s_size - 1, tr + s_size, tc, s_size);
		}
		if (dr <= (tr + s_size - 1) && dc > (tc + s_size - 1))
		{
			a[tr + s_size - 1][tc + s_size - 1] = t;
			a[tr + s_size][tc + s_size - 1] = t;
			a[tr + s_size][tc + s_size] = t;
			++t;
			Chess(a, dr, dc, tr, tc + s_size, s_size);             //右上角子棋盘递归处理
			Chess(a, tr + s_size - 1, tc + s_size - 1, tr, tc, s_size); //左上角子棋盘递归处理
			Chess(a, tr + s_size, tc + s_size - 1, tr + s_size, tc, s_size); //左下角子棋盘递归处理
			Chess(a, tr + s_size, tc + s_size, tr + s_size, tc + s_size, s_size); //右下角子棋盘递归处理
		}
		if (dr>(tr + s_size - 1) && dc <= (tc + s_size - 1))	/*特殊方块在左下部分*/
		{
			a[tr + s_size - 1][tc + s_size - 1] = t;
			a[tr + s_size - 1][tc + s_size] = t;
			a[tr + s_size][tc + s_size] = t;
			++t;
			Chess(a, dr, dc, tr + s_size, tc, s_size);
			Chess(a, tr + s_size - 1, tc + s_size - 1, tr, tc, s_size);
			Chess(a, tr + s_size - 1, tc + s_size, tr, tc + s_size, s_size);
			Chess(a, tr + s_size, tc + s_size, tr + s_size, tc + s_size, s_size);
		}
		if (dr>(tr + s_size - 1) && dc>(tc + s_size - 1))	/*特殊方块在右下部分*/
		{
			a[tr + s_size][tc + s_size - 1] = t;
			a[tr + s_size - 1][tc + s_size - 1] = t;
			a[tr + s_size - 1][tc + s_size] = t;
			++t;
			Chess(a, dr, dc, tr + s_size, tc + s_size, s_size);
			Chess(a, tr + s_size, tc + s_size - 1, tr + s_size, tc, s_size);
			Chess(a, tr + s_size - 1, tc + s_size - 1, tr, tc, s_size);
			Chess(a, tr + s_size - 1, tc + s_size, tr, tc + s_size, s_size);
		}
	}
}

Chess::~Chess()
{

}

int main()
{
	int i, j, dr = 0, dc = 0;
	int a[N][N];
	cout << "please input dr(0<dr<" << N << ")" << endl;
	cin >> dr;
	cout << "please input dc(0<dc<" << N << ")" << endl;
	cin >> dc;
	a[dr][dc] = 0;
	Chess::Chess(a, dr, dc, 0, 0, N);
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n" << endl;
	}
	system("pause");
	return 0;

}
