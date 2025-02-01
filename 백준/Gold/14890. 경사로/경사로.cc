#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
다른 경사로는 고려x
그냥 놓았을 때 지나갈 수 있다면 길이다.

i. 진행중 높은걸 만난 경우
	- 이전까지의 개수와 L을 비교
	- L 이상이면, PASS
	- L 미만, break

ii. 진행중 낮은 걸 만난 경우
	- 다음 것들의 개수 count
	- L 이상이면, PASS -> 위치 +L로 이동
	- L 미만, break

	7 1
3 3 4 4 4 4 3
2 3 3 3 3 3 2
2 2 3 2 2 2 2
3 3 3 2 2 3 3
4 3 3 3 3 4 4
4 4 4 3 4 4 4
4 4 4 4 4 4 4


4 1
4 4 4 3
5 4 3 4
5 4 4 5
4 4 5 5
*/
int N, L;
int board[101][101];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	
	int ans = 0;
	//가로 길
	for (int i = 0; i < N; i++)
	{
		int max_diff = 0;
		for (int j = 1; j < N; j++)
		{
			max_diff = max(max_diff, abs(board[i][j - 1] - board[i][j]));
		}
		if (max_diff == 0)
		{
			ans++;
			continue;
		}
		if (max_diff > 1) {  continue; }
		bool p = true;
		//경사로 놓아보기
		int cnt = 1;
		int temp = board[i][0];
		for (int j = 1; j < N; j++)
		{
			if (temp == board[i][j])
			{
				cnt++;
				continue;
			}
			if (temp < board[i][j])
			{
				if (cnt >= L)
				{
					cnt = 1;
					temp = board[i][j];
					continue;
				}
				p = false;

				break;
			}
			else // temp > board[i][j]
			{
				int t_cnt = 0;
				for (int l = j; l < N; l++)
				{
					if (board[i][l] == temp - 1)
					{
						t_cnt++;
						if (t_cnt == L)
						{
							break;
						}
					}else break;
				}
				if (t_cnt == L)
				{
					j += L - 1;
					if (j < N)
					{
						temp = board[i][j];
						cnt = 0;
					}
				}
				else
				{

					p = false;
					break;
				}
			}
		}
		if (p)
		{
			ans++;
		}
	}
	//세로 길 
	for (int i = 0; i < N; i++)
	{
		int max_diff = 0;
		for (int j = 1; j < N; j++)
		{
			max_diff = max(max_diff, abs(board[j-1][i] - board[j][i]));
		}
		if (max_diff == 0)
		{
			ans++;
			continue;
		}
		if (max_diff > 1) {  continue; }
		bool p = true;
		//경사로 놓아보기
		int cnt = 1;
		int temp = board[0][i];
		for (int j = 1; j < N; j++)
		{
			if (temp == board[j][i])
			{
				cnt++;
				continue;
			}
			if (temp < board[j][i])
			{
				if (cnt >= L)
				{
					cnt = 1;
					temp = board[j][i];
					continue;
				}
				p = false;

				break;
			}
			else // temp > board[j][i]
			{
				int t_cnt = 0;
				for (int l = j; l < N; l++)
				{
					if (board[l][i] == temp - 1)
					{
						t_cnt++;
						if (t_cnt == L)
						{
							break;
						}
					}else break;
				}
				if (t_cnt == L)
				{
					j += L - 1;
					if (j < N)
					{
						temp = board[j][i];
						cnt = 0;
					}
				}
				else {  p = false; break; }
			}
		}
		if (p) ans++;
	}
	cout << ans;
}