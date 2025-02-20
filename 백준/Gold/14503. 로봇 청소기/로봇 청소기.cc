#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int board[51][51];

int forward_dx[] = {-1, 0, 1, 0};
int forward_dy[] = { 0, 1, 0, -1 };

int back_dx[] = { 1,0,-1,0 };
int back_dy[] = { 0,-1,0,1 };

int ans;

int change_d(int d)
{
	if (d == 0)
	{
		return 3;
	}
	if (d == 1)
	{
		return 0;
	}
	if (d == 2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

/*
해당 칸 청소
*/
void clean(int r, int c)
{
	if (board[r][c] == 0) ans++;
	board[r][c] = 2;
}

/* 
* 현재 위치 기준 4방향의 청소여부 확인
* true: 청소할거 남음
* false: 청소할데 없음
*/
bool isNotClean(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nr = r + forward_dx[i];
		int nc = c + forward_dy[i];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
		if (board[nr][nc] == 0) return true;
	}
	return false;
}

/*
현재 위치에서 후진 가능한지? => 불가능하면 종료
*/
bool isBack(int r, int c, int d)
{
	int nr = r + back_dx[d];
	int nc = c + back_dy[d];
	if (nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
	if (board[nr][nc] == 1) return false;

	return true;
}

/*
현재 위치에서 후진
*/
pair<int,int> goBack(int r, int c, int d)
{
	int nr = r + back_dx[d];
	int nc = c + back_dy[d];
	return { nr,nc };
}

/*
현재 위치에서 전진 가능한지?
*/
bool isFor(int r, int c, int d)
{
	int nr = r + forward_dx[d];
	int nc = c + forward_dy[d];
	if (nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
	if (board[nr][nc] == 0) return true; //청소안된 칸이면 ㄱ
	return false;
}

/*
현재 위치에서 전진
*/
pair<int, int> goFor(int r, int c, int d)
{
	int nr = r + forward_dx[d];
	int nc = c + forward_dy[d];
	return { nr,nc };
}

//벽 1
//더러움 0
//청소됨 2
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int r, c, d; cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	while (true)
	{
		clean(r, c);
		if (!isNotClean(r, c)) //청소할 칸이 없는 경우
		{
			if (isBack(r, c, d)) //뒤로 갈 수 있다면
			{
				pair<int, int> t = goBack(r, c, d);
				r = t.first;
				c = t.second;
				continue; //후진하고 처음으로.
			}
			else //뒤로 갈 수 없다면
			{
				cout << ans;
				return 0; //종료
			}
		}
		else // 청소할 칸이 있는 경우
		{
			while (true)
			{
				d = change_d(d); //반시계 회전
				if (isFor(r, c, d)) //앞칸이 청소 안된 칸이면?
				{
					pair<int, int> t = goFor(r, c, d);
					r = t.first;
					c = t.second;
					break; //앞으로 한 칸 이동후 처음으로 돌아감
				}
			}
		}
	}

	return 0;
}