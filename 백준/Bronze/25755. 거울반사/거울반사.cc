#include <iostream>

using namespace std;

char board[21][21];
char ans[21][21];

char W;
int N;
int n;

void LRfunc()
{
	n = N - 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '1') ans[i][n - j] = '1';
			else if (board[i][j] == '8') ans[i][n - j] = '8';
			else if (board[i][j] == '2') ans[i][n - j] = '5';
			else if (board[i][j] == '5') ans[i][n - j] = '2';
			else ans[i][n - j] = '?';
		}
	}
}
void UDfunc()
{
	n = N - 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '1') ans[n - i][j] = '1';
			else if (board[i][j] == '8') ans[n - i][j] = '8';
			else if (board[i][j] == '2') ans[n - i][j] = '5';
			else if (board[i][j] == '5') ans[n - i][j] = '2';
			else ans[n - i][j] = '?';
		}
	}
}

int main()
{
	cin >> W >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)cin >> board[i][j];
	}
	if (W == 'L' || W == 'R') LRfunc();
	else UDfunc();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cout << ans[i][j]<<' ';
		cout << endl;
	}
	return 0;
}