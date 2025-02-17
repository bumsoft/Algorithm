#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//8방향 너비우선탐색

int dx[]{ 0,1,0,-1,-1, -1,1,1 };
int dy[]{ 1,0,-1,0, -1, 1, -1, 1 };

int H, W;
int board[1001][1001];
bool vis[1001][1001];


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> H >> W;
	char c;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> c;
			if (c == '.')board[i][j] = -1;
			else board[i][j] = c - 48;
		}
	}
	priority_queue<pair<int,pair<int,int>>> PQ;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == -1)
			{
				PQ.push({ -1,{i,j} });
				vis[i][j] = 1;
			}
		}
	}

	int level = 0;
	int ans = 0;
	while (!PQ.empty())
	{
		int l = -PQ.top().first;
		ans = l;
		int r = PQ.top().second.first;
		int c = PQ.top().second.second;
		PQ.pop();

		for (int i = 0; i < 8; i++)
		{
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
			if (vis[nr][nc]) continue;

			//모래성인 경우
			if (board[nr][nc] != -1)
			{
				board[nr][nc]--;
				if (board[nr][nc] == 0)
				{
					PQ.push({ -(l + 1),{nr,nc} });
					board[nr][nc] = -1;
					vis[nr][nc] = true;
				}
			}
			else
			{
				vis[nr][nc] = true;
				PQ.push({ -l,{nr,nc} });
			}
		}
	}
	cout << ans-1;
	return 0;
}