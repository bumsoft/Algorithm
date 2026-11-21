#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
using ll = long long;

int N, ans;
int original_board[20][20];
int board[20][20];
int d[4] = { 1,2,3,4 };
int order[5];
stack<int> st;
void move(int n)
{
	if (n == 1)//상
	{
		for (int i = 0; i < N; i++)//가로
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if(board[j][i]!=0)st.push(board[j][i]);
			}
			//합치기
			int index = 0;
			while (!st.empty())
			{
				int now = st.top();
				st.pop();
				if (st.empty())
				{
					board[index++][i] = now;
					break;
				}
				if (st.top() == now)
				{
					board[index++][i] = now * 2;
					st.pop();
				}
				else
				{
					board[index++][i] = now;
				}
			}
			while (index!=N)
			{
				board[index++][i] = 0;
			}
		}
	}
	if (n == 2)//하
	{
		for (int i = 0; i < N; i++)//가로
		{
			for (int j = 0; j < N; j++)
			{
				if (board[j][i] != 0)st.push(board[j][i]);
			}
			//합치기
			int index = N-1;
			while (!st.empty())
			{
				int now = st.top();
				st.pop();
				if (st.empty())
				{
					board[index--][i] = now;
					break;
				}
				if (st.top() == now)
				{
					board[index--][i] = now * 2;
					st.pop();
				}
				else
				{
					board[index--][i] = now;
				}
			}
			while (index != -1)
			{
				board[index--][i] = 0;
			}
		}
	}
	if (n == 3)//좌
	{
		for (int i = 0; i < N; i++)//세로
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (board[i][j] != 0)st.push(board[i][j]);
			}
			//합치기
			int index = 0;
			while (!st.empty())
			{
				int now = st.top();
				st.pop();
				if (st.empty())
				{
					board[i][index++] = now;
					break;
				}
				if (st.top() == now)
				{
					board[i][index++] = now * 2;
					st.pop();
				}
				else
				{
					board[i][index++] = now;
				}
			}
			while (index != N)
			{
				board[i][index++] = 0;
			}
		}
	}
	if (n == 4)//우
	{
		for (int i = 0; i < N; i++)//행
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != 0)st.push(board[i][j]);
			}
			//합치기
			int index = N - 1;
			while (!st.empty())
			{
				int now = st.top();
				st.pop();
				if (st.empty())
				{
					board[i][index--] = now;
					break;
				}
				if (st.top() == now)
				{
					board[i][index--] = now * 2;
					st.pop();
				}
				else
				{
					board[i][index--] = now;
				}
			}
			while (index != -1)
			{
				board[i][index--] = 0;
			}
		}
	}
}

void back(int n)
{
	if (n == 5)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = original_board[i][j];

		for (int i = 0; i < 5; i++)
		{
			move(order[i]);
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	for (int i = 1; i < 5; i++)
	{
		order[n] = i;
		back(n + 1);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
			cin >> original_board[i][j];
	}
	back(0);
	cout << ans;
	return 0;
}