#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N*M을 ㄱ자 모양으로 여러개 만들고, 그 부메랑들의 합
// 부메랑의 가운데는 x2효과

//최대 5*5 크기


int N, M;
int board[5][5];

bool vis[5][5];
int ans;

int dx1[] = { -1,0 };
int dy1[] = { 0,1 };

int dx2[] = { -1, 0 };
int dy2[] = { 0, -1 };

int dx3[] = { 0,1 };
int dy3[] = { -1,0 };

int dx4[] = { 0,1 };
int dy4[] = { 1,0 };

void backTracking(int i, int j, int sum, int depth)
{
	//범위 벗어나면, 종료
	if (i >= N)
	{
		ans = max(ans, sum);
		return;
	}
	//이미 사용한 곳이면,
	if (vis[i][j])
	{
		if (j + 1 == M) return backTracking(i + 1, 0, sum, depth+1);
		else return backTracking(i, j + 1, sum, depth + 1);
	}

	vis[i][j] = 1;
	int ni1, ni2, nj1, nj2;
	//부메랑 만들기.
	//111111111111
	ni1 = i + dx1[0];
	nj1 = j + dy1[0];

	ni2 = i + dx1[1];
	nj2 = j + dy1[1];
	if (ni1 < N && nj1 < M && ni2 < N && nj2 < M && ni1 >= 0 && ni2 >= 0 && nj1 >= 0 && nj2 >= 0 && !vis[ni1][nj1] && !vis[ni2][nj2])
	{
		vis[ni1][nj1] = 1;
		vis[ni2][nj2] = 1;
		if (j + 1 == M)
		{
			backTracking(i+1, 0, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		else
		{
			backTracking(i, j+1, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		vis[ni1][nj1] = 0;
		vis[ni2][nj2] = 0;
	}
	//22222222222
	ni1 = i + dx2[0];
	nj1 = j + dy2[0];

	ni2 = i + dx2[1];
	nj2 = j + dy2[1];

	if (ni1 < N && nj1 < M && ni2 < N && nj2 < M && ni1 >= 0 && ni2 >= 0 && nj1 >= 0 && nj2 >= 0 && !vis[ni1][nj1] && !vis[ni2][nj2])
	{
		vis[ni1][nj1] = 1;
		vis[ni2][nj2] = 1;
		if (j + 1 == M)
		{
			backTracking(i + 1, 0, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		else
		{
			backTracking(i, j + 1, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		vis[ni1][nj1] = 0;
		vis[ni2][nj2] = 0;
	}
	//33333333333333333
	ni1 = i + dx3[0];
	nj1 = j + dy3[0];

	ni2 = i + dx3[1];
	nj2 = j + dy3[1];

	if (ni1 < N && nj1 < M && ni2 < N && nj2 < M && ni1 >= 0 && ni2 >= 0 && nj1 >= 0 && nj2 >= 0 && !vis[ni1][nj1] && !vis[ni2][nj2])
	{
		vis[ni1][nj1] = 1;
		vis[ni2][nj2] = 1;
		if (j + 1 == M)
		{
			backTracking(i + 1, 0, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		else
		{
			backTracking(i, j + 1, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		vis[ni1][nj1] = 0;
		vis[ni2][nj2] = 0;
	}
	//444444444444444444
	ni1 = i + dx4[0];
	nj1 = j + dy4[0];

	ni2 = i + dx4[1];
	nj2 = j + dy4[1];
	if (ni1 < N && nj1 < M && ni2 < N && nj2 < M && ni1 >= 0 && ni2 >= 0 && nj1 >= 0 && nj2 >= 0 && !vis[ni1][nj1] && !vis[ni2][nj2])
	{
		vis[ni1][nj1] = 1;
		vis[ni2][nj2] = 1;
		if (j + 1 == M)
		{
			backTracking(i + 1, 0, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		else
		{
			backTracking(i, j + 1, sum + board[i][j] * 2 + board[ni1][nj1] + board[ni2][nj2], depth + 1);
		}
		vis[ni1][nj1] = 0;
		vis[ni2][nj2] = 0;
	}
	//부메랑 x
	vis[i][j] = 0;
	if (j + 1 == M)
	{
		backTracking(i + 1, 0, sum, depth + 1);
	}
	else
	{
		backTracking(i, j + 1, sum, depth + 1);
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	backTracking(0, 0, 0, 0);
	cout << ans;

	return 0;
}