#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[]{ 0,1,0,-1 };
int dy[]{ -1,0,1,0 };

//마지막은 알파
int lx[4][10]{
	{2,1,1,1,0,-1,-1,-1,-2,0}, //좌
	{2,1,1,0,0,0,0,-1,-1,1}, //하
	{2,1,1,1,0,-1,-1,-1,-2,0}, //우
	{1,1,0,0,0,0,-1,-1,-2,-1}  //상
};

int ly[4][10]{
	{0,-1,0,1,-2,-1,0,1,0,-1}, //좌
	{0,-1,1,-2,-1,1,2,-1,1,0}, //하
	{0,-1,0,1,2,-1,0,1,0,1}, //우
	{-1,1,-2,-1,1,2,-1,1,0,0}  //상
};

int p[4][10]{
	{2,10,7,1,5,10,7,1,2,-1}, //좌
	{5,10,10,2,7,7,2,1,1,-1}, //하
	{2,1,7,10,5,1,7,10,2,-1}, //우
	{1,1,2,7,7,2,10,10,5,-1}  //상
};
int A[500][500];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	int r = N / 2;
	int c = N / 2;
	int ans = 0; //버려지는 모래
	int dir = 0;
	for (int i = 1; ; i++) //좌 하 우 상
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < i; k++)
			{
				r += dx[dir % 4];
				c += dy[dir % 4];
				int remo = 0;
				for (int l = 0; l < 9; l++)
				{
					int nr = r + lx[dir % 4][l];
					int nc = c + ly[dir % 4][l];
					int per = p[dir % 4][l];

					int move = A[r][c] * per / 100; //이동하는 모래
					remo += move;

					if (nr < 0 || nr >= N || nc < 0 || nc >= N)
					{
						ans += move;
					}
					else A[nr][nc] += move;
				}
				//[9]
				int nr = r + lx[dir % 4][9];
				int nc = c + ly[dir % 4][9];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				{
					ans += A[r][c] - remo;
				}
				else A[nr][nc] += A[r][c] - remo;
				A[r][c] = 0;

				if (r == 0 && c == 0) break;
			}
			dir++;
			if (r == 0 && c == 0) break;
		}
		if (r == 0 && c == 0) break;
	}
	cout << ans;
	return 0;
}