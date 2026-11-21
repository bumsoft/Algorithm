#include <iostream>
#include <queue>
#include <climits>
using namespace std;
using ll = long long;

int board[101][101];
int R, C;
char order[100];

int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };

pair<int, int> A;

pair<int, int> B[10000];
int bNum;

bool check1()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j] == -1)
			{
				return true;
			}
		}
	}
	return false;
}

void check2()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j] >1)
			{
				board[i][j] = 0;
				for (int l = 0; l < bNum; l++)
				{
					if (B[l].second == i && B[l].first == j)
					{
						B[l].first = -10;
						B[l].second = -10;
					}
				}

			}
		}
	}
}

//A와의 택시거리 계산 후 가장 가까워지는 좌표 반환
pair<int, int> taxi(int x, int y)
{
	pair<int, int> save;
	int dis = INT_MAX;
	for (int i = 0; i < 9; i++)
	{
		if (abs(A.first - (x + dx[i])) + abs(A.second - (y + dy[i])) < dis)
		{
			if (x + dx[i] == 0 || x + dx[i] > C || y + dy[i] == 0 || y + dy[i] > R) continue;

			save.first = x + dx[i];
			save.second = y + dy[i];
			dis = abs(A.first - (x + dx[i])) + abs(A.second - (y + dy[i]));
		}
	}
	return save;
}

bool crazyMove()
{
	for (int i = 0; i < bNum; i++)
	{
		if (B[i].first == -10) continue;

		board[B[i].second][B[i].first]--;
		B[i] = taxi(B[i].first, B[i].second);

		if (B[i].first == A.first && B[i].second == A.second)
		{
			return true;
		}
		board[B[i].second][B[i].first]++;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	char c;


	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> c;
			if (c == 'I') {
				board[i][j] = -2;
				A = { j,i };
			}
			else if (c == 'R') {
				board[i][j] = 1;
				B[bNum].first = j;
				B[bNum].second = i;
				bNum++;
			}
		}
	}
	int t = 0;
	while (cin >> c)
	{
		order[t++] = c;
	}
	int ans = 0;
	for (int i = 0; i < t; i++)
	{
		//종수 움직임
		board[A.second][A.first] = 0;
		ans++;
		A.first += dx[order[i] - 49];
		A.second += dy[order[i] - 49];
		board[A.second][A.first] += -2;

		//충돌확인1
		if (check1())
		{
			cout << "kraj " << ans;
			return 0;
		}

		//미친아두이노 움직임
		if (crazyMove())
		{
			cout << "kraj " << ans;
			return 0;
		}

		//충돌확인2
		check2();
	}
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j] == 0)cout << '.';
			else if (board[i][j] == -2) cout << 'I';
			else cout << 'R';
		}
		cout << '\n';
	}

	return 0;
}