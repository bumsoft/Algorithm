#include <bits/stdc++.h>
using namespace std;

int board[100][100];
bool ss[100][100]; //세워져있으면 false 넘어져있으면 true
int N, M, R;
int score;
void f(int c, int r, char l)
{
	if (!(c >= 0 && c < N) || !(r >= 0 && r < M))return;
	if (ss[c][r])return;
	if (l == 'N')
	{
		ss[c][r] = true;
		score++;
		for (int i = 1; i < board[c][r]; i++)
		{
			f(c - i, r, l);
		}

	}
	else if (l == 'S')
	{
		ss[c][r] = true;
		score++;
		for (int i = 1; i < board[c][r]; i++)
		{
			f(c + i, r, l);
		}
	}
	else if (l == 'E')
	{
		ss[c][r] = true;
		score++;
		for (int i = 1; i < board[c][r]; i++)
		{
			f(c, r + i, l);
		}
	}
	else
	{
		ss[c][r] = true;
		score++;
		for (int i = 1; i < board[c][r]; i++)
		{
			f(c, r - i, l);
		}
	}
}
void s(int c,int r)
{
	ss[c][r] = false;
}

int main()
{
	int X, Y;
	char D;
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> X >> Y >> D;
		f(X-1, Y-1, D);
		cin >> X >> Y;
		s(X-1, Y-1);
	}
	cout << score << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (ss[i][j]) cout << 'F' << ' ';
			else cout << 'S' << ' ';
		cout << '\n';
	}
	return 0;
}