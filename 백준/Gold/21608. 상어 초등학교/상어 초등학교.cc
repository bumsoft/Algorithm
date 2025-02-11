#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N*N 교실
// 학생수 N*N명(1~N*N)

//각 학생이 좋아하는 학생 4명
//인접: 상하좌우

//1. 비어있는 칸 중 좋아하는 학생이 인접한 칸이 가장 많은 칸으로 자리를 정함
//2. 1에서, 여러 개라면, 인접한 빈 칸이 많은 칸에 배치한다.
//3. 2에서, 여러 개라면, 행/열 작은 순을 배치함

int N;

int board[21][21];

vector<int> like[401];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

//각 칸에 대해, 좋아하는 사람 수와 빈칸 개수 반환
pair<int,int> sol1(int i, int j, int n)
{
	int num = 0;
	int blank = 0;
	for (int k = 0; k < 4; k++)
	{
		int ni = i + dx[k];
		int nj = j + dy[k];

		if (ni >= N || ni < 0 || nj >= N || nj < 0) continue;
		if (board[ni][nj] == 0)
		{
			blank++;
			continue;
		}
		for (int l = 0; l < 4; l++)
		{
			if (board[ni][nj] == like[n][l])
			{
				num++;
				break;
			}
		}
	}
	return { num,blank };
}

//각 칸에 대해, 좋아하는 사람 수 반환
int sol2(int i, int j, int n)
{
	int num = 0;
	for (int k = 0; k < 4; k++)
	{
		int ni = i + dx[k];
		int nj = j + dy[k];

		if (ni >= N || ni < 0 || nj >= N || nj < 0) continue;
		for (int l = 0; l < 4; l++)
		{
			if (board[ni][nj] == like[n][l])
			{
				num++;
				break;
			}
		}
	}
	return num;
}

void locate(int a) //a번을 배치시키는 함수
{	
	pair<int, int> save;
	int max_num = -1;
	int max_blank = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 0) continue;
			pair<int, int> temp = sol1(i, j, a);
			if (max_num < temp.first)
			{
				max_num = temp.first;
				max_blank = temp.second;
				save = { i,j };
				continue;
			}
			if (max_num == temp.first && max_blank < temp.second)
			{
				max_blank = temp.second;
				save = { i,j };
				continue;
			}
		}
	}
	board[save.first][save.second] = a;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	int a, b;
	for (int i = 0; i < N*N; i++)
	{
		cin >> a;
		for (int j = 0; j < 4; j++)
		{
			cin >> b;
			like[a].push_back(b);
		}
		locate(a);
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (sol2(i, j, board[i][j]))
			{
			case 0:
				ans += 0;
				break;
			case 1:
				ans += 1;
				break;
			case 2:
				ans += 10;
				break;
			case 3:
				ans += 100;
				break;
			default:
				ans += 1000;
			}
		}
	}
	cout << ans;

	return 0;
}