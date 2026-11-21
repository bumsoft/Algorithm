//행렬 A를 B로 바꾸는데 필요한 연산횟수의 최솟값
//연산: 3x3크기의 부분행렬의 모든 원소를 뒤집는 것.(~연산)

#include <bits/stdc++.h>
using namespace std;

char Amatrix[51][51];
char Bmatrix[51][51];
bool matrix[51][51];
int N, M;
int ans;

void cal(int row, int col)
{
	for (int i = row; i < row + 3; i++)
	{
		for (int j = col; j < col + 3; j++)
		{
			if (matrix[i][j])
			{
				matrix[i][j] = false;
			}
			else
			{
				matrix[i][j] = true;
			}
		}
	}
}


int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < M; j++) cin >> Amatrix[i][j];
	}	
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < M; j++) cin >> Bmatrix[i][j];
	}
	//같으면 0
	if (memcmp(Amatrix, Bmatrix, sizeof(Amatrix))==0)
	{
		cout<<0;
		return 0;
	}
	//3*3보다작으면 -1
	if (N < 3 || M < 3)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Amatrix[i][j] == Bmatrix[i][j]) matrix[i][j] = true;
			else matrix[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!matrix[i][j])
			{
				if (i + 2 >= N || j + 2 >= M)
				{
					cout << -1;
					return 0;
				}
				else 
				{
					cal(i, j); 
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}