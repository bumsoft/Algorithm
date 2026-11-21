#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[1001][1001];
bool vis_[1001][1001];
int* arr[1001][1001];
queue<pair<int, int>> Q;
int* zero;
//영역들로 나눌거임
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	char temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			board[i][j] = temp - '0';
		}
	}
	zero = (int*)malloc(4); *zero = 0;
	int r, c, ii, jj;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis_[i][j])continue;
			if (board[i][j] == 1) { arr[i][j] = zero; vis_[i][j] = true; continue; }
			vis_[i][j] = true;
			arr[i][j] = (int*)malloc(4);
			*arr[i][j] = 1;
		//	cout << "(" << i << "," << j << ")\n";
			for (int l = 0; l < 4; l++)
			{
				r = i + dx[l];
				c = j + dy[l];
				if (r >= N || c >= M || r < 0 || c < 0 || board[r][c]==1 || vis_[r][c])continue;
				Q.push({ r,c });
			}
			//너비우선탐색
			while (!Q.empty())
			{
				ii = Q.front().first;
				jj = Q.front().second;
				Q.pop();
				if (vis_[ii][jj]) continue;
				vis_[ii][jj] = true;
				arr[ii][jj] = arr[i][j];
				(*arr[i][j]) += 1;
				for (int l = 0; l < 4; l++)
				{
					r = ii + dx[l];
					c = jj + dy[l];
					if (r >= N || c >= M || r < 0 || c < 0 || board[r][c] == 1 || vis_[r][c])continue;
					Q.push({ r,c });
				}
			}

		}
	}


	int ans;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)//원래 빈칸인곳
			{
				cout << 0;
				continue;
			}
			ans = 1;
			set<int*> s;
			for (int a = 0; a < 4; a++)
			{
				 r = i + dx[a];
				 c = j + dy[a];
				if (r >= N || c >= M || r < 0 || c < 0)continue;
				s.insert(arr[r][c]);
			}
			for (int* t : s)
			{
				ans += *t;
			}
			cout << ans % 10;
		}
		cout << '\n';
	}
	return 0;
}