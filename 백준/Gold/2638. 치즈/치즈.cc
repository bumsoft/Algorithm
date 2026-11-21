#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//0. 0,0을 큐에 넣는다.

//1. 큐가 빌 때 까지 bfs로 치즈가 아닌 곳을 방문한다.
//2. 치즈를 방문해야한다면, 방문하지 않고, 치즈++를 해준다.
//3. 치즈++ 후 2가 된 치즈는  두번 째 큐에 넣는다.
//4. bfs가 끝나면, 시간++ 하고, 1~3을 반복한다.

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int N, M;
int board[101][101];
int save[101][101];
bool vis[101][101];
priority_queue<pair<int,pair<int, int>>> PQ;

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
	int time;
	PQ.push({ 0,{ 0,0 } });
	vis[0][0] = true;
	while (!PQ.empty())
	{
		time = -PQ.top().first;
		int i = PQ.top().second.first;
		int j = PQ.top().second.second;
		PQ.pop();
		for (int l = 0; l < 4; l++)
		{
			int ni = i + dx[l];
			int nj = j + dy[l];
			//범위 벗어남
			if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			//방문함
			if (vis[ni][nj]) continue;
			//치즈임
			if (board[ni][nj] == 1)
			{
				int stat = save[ni][nj];
				if (stat == 1)
				{
					PQ.push({ -(time + 1),{ni,nj} });
					vis[ni][nj] = true;
				}
				else
				{
					save[ni][nj]++;
				}
				continue;
			}
			PQ.push({ -(time),{ni,nj} });
			vis[ni][nj] = true;
		}

	}
	cout << time;
	return 0;
}