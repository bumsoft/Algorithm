#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
N-Queen
백트래킹?
=> 경우의 수 출력

한 줄에는 반드시 하나의 퀸
*/

int N;
int ans;
bool board[15][15];

bool ck(int r, int c)
{
	if (board[r][c]) return false;
	//상하좌우
	for (int i = 1; i <= N; i++)
	{
		//if (board[r][i] == true) return 1; //같은 행 무조건 없음.
		if (board[i][c] == true) return 0; //같은 열
	}
	/*
	1 2
	 0
	3 4
	*/
	bool cc = false;
	for (int i = 1; ; i++)
	{
		//1
		if (!(r - i <= 0) && !(c - i <= 0))
		{
			if (board[r - i][c - i]) return 0;
		}
		else break;
	}
	for (int i = 1; ; i++)
	{
		//2
		if (!(r - i <= 0) && !(c + i > N))
		{
			if (board[r - i][c + i]) return 0;
		}
		else break;
	}
	for (int i = 1; ; i++)
	{
		//3
		if (!(r + i > N) && !(c - i <= 0))
		{
			if (board[r + i][c - i]) return 0;
		}
		else break;
	}
	for (int i = 1; ; i++)
	{
		//4
		if (!(r + i > N) && !(c + i > N))
		{
			if (board[r + i][c + i]) return 0;
		}
		else break;
	}
	return 1;

}

void backTracking(int n, int r, int c)
{
	if (n == 0)
	{
		ans++;
		return;
	}
	//r c가 범위 벗어난 경우 처리
	if (r > N)
	{
		return;
	}
	if (r + n - 1 != N) return;

	if (ck(r,c)) //현재 위치에 놓을 수 있다면?
	{
		board[r][c] = true;
		backTracking(n - 1, r + 1, 1);
		board[r][c] = false;
	}

	//현재 위치에 설치 안하고 다음으로
	if (c == N) return;
	else backTracking(n, r, c + 1);
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	backTracking(N, 1, 1);
	cout << ans;

}