#include <iostream>

using namespace std;

int M, N, U, L, R, D;
char board[21][21];

//가로 : N+L+R max = 10+5+5 == 20
//세로 : M+U+D max = 10+5+5 == 20

int main()
{
	cin >> M >> N >> U >> L >> R >> D;

	int l = N + L + R;
	int h = M + U + D;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					board[i][j] = '#';
				}
				else
				{
					board[i][j] = '.';
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					board[i][j] = '.';
				}
				else
				{
					board[i][j] = '#';
				}
			}
		}
	}
	int m = U;
	int n;
	for (int i = 0; i < M; i++)
	{
		n = L;
		for (int j = 0; j < N; j++)
		{
			cin >> board[m][n];
			n++;
		}
		m++;
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++) cout << board[i][j];
		cout << endl;
	}
	return 0;
}