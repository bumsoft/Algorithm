#include <bits/stdc++.h>
using namespace std;

/* 
* 1388 바닥장식
* 방은 직사각형, 
* => 가로로 연결된 - 개수
* => + 세로로 연결된 | 개수
*/

int N, M;
char arr[50][50];

int ans1;
int ans2;

bool con = false;

int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	//행 탐색
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '|')
			{
				if (con)
				{
					ans1++;
					con = 0;
				}
			}
			else
			{
				con = 1;
			}
		}
		if (con)
		{
			ans1++;
			con = 0;
		}
	}
	//열 탐색
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] == '-')
			{
				if (con)
				{
					ans1++;
					con = 0;
				}
			}
			else
			{
				con = 1;
			}
		}
		if (con)
		{
			ans1++;
			con = 0;
		}
	}
	cout << ans1 + ans2;

	return 0;
}
