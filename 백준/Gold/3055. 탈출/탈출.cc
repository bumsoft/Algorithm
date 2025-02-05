#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//물 시작점에서 bfs => 각 칸이 물에 차는 시간을 기록
//고슴도치가 bfs => (각 칸에 도달한 시간) < (물이 차는 시간)이라면, 진행가능

int R, C;
char board[51][51];
int t[51][51]; //물 차는 시간

pair<int, int> cave;
pair<int, int> start;
vector<pair<int, int>> water;

bool vis1[51][51];
bool vis2[51][51];

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'D') cave = { i,j };
			else if (board[i][j] == 'S') start = { i,j };
			else if (board[i][j] == '*') water.push_back({ i,j });
			t[i][j] = INT_MAX;
		}
	}
	//물 BFS
	queue<pair<int, pair<int, int>>> Q; //<도달한 시간,<i,j>>
	for (int i = 0; i < water.size(); i++)
	{
		Q.push({ 0,water[i]});
		vis1[water[i].first][water[i].second] = true;
		t[water[i].first][water[i].second] = 0;
	}
	while (!Q.empty())
	{
		int r = Q.front().second.first;
		int c = Q.front().second.second;
		int cost = Q.front().first;
		Q.pop();

		t[r][c] = cost;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (vis1[nr][nc] || board[nr][nc] == 'X' || board[nr][nc] == 'D') continue; //방문했거나, 돌이거나, 소굴이라면.
			vis1[nr][nc] = true;

			Q.push({ cost + 1,{nr,nc} });
		}
	}
	//고슴도치 BFS
	Q.push({ 0,start });
	vis2[start.first][start.second] = true;
	while (!Q.empty())
	{
		int r = Q.front().second.first;
		int c = Q.front().second.second;
		int cost = Q.front().first;
		Q.pop();

		if (cave == make_pair(r,c))
		{
			cout << cost;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (vis2[nr][nc] || board[nr][nc] == 'X') continue; //방문했거나, 돌이거나
			if (t[nr][nc] <= cost + 1) continue;
			vis2[nr][nc] = true;

			Q.push({ cost + 1,{nr,nc} });
		}
	}
	cout << "KAKTUS";


	return 0;
}