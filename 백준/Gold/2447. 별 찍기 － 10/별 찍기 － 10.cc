#include <iostream>
using namespace std;

char board[2500][2500];
int N;
int NN;

/*
(1,1) (1,4) (1,7) .....
(4,1) (4,4) (4,7) .....



*/

void makefunc()
{
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((i / NN) % 3 == 1 && (j / NN) % 3 == 1) board[i][j] = 'n';
			}
		}
		NN /= 3;
		if (NN == 0) break;
	}
}

int main()
{
	cin >> N;
	NN = N/3;
	makefunc();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 'n') cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}
	return 0;
}