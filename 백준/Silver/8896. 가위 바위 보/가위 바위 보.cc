#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// 각 로봇은 길이가 k인 문자열 가짐
// 승리한 로봇들끼리 게임함
// 하나만 남을 때 까지.

// k라운드 이후, 로봇이 2개 이상이면 무승부

// 문자열의 각 자리는 각 라운드에서의 낼 가위바위보

int T, N;

bool win[10];
string arr[10];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			win[i] = true;
			cin >> arr[i];
		}

		for (int i = 0; i < arr[0].length(); i++) //라운드
		{
			bool r = 0;
			bool s = 0;
			bool p = 0;
			for (int j = 0; j < N; j++)
			{
				if (!win[j]) continue;
				if (arr[j][i] == 'R') r = true;
				else if (arr[j][i] == 'S') s = true;
				else p = true;
			}
			if (r && s && p) continue;
			else if (r && s) //R
			{
				for (int j = 0; j < N; j++)
				{
					if (!win[j]) continue;
					if (arr[j][i] == 'S') win[j] = false;
				}
			}
			else if (r && p)
			{
				for (int j = 0; j < N; j++)
				{
					if (!win[j]) continue;
					if (arr[j][i] == 'R') win[j] = false;
				}
			}
			else if (s && p)
			{
				for (int j = 0; j < N; j++)
				{
					if (!win[j]) continue;
					if (arr[j][i] == 'P') win[j] = false;
				}
			}
		}
		int num = -1;
		bool c = false;
		for (int i = 0; i < N; i++)
		{
			if (win[i])
			{
				if (num != -1) //무승부
				{
					cout << 0 << '\n';
					c = true;
					break;
				}
				else
				{
					num = i;
				}
			}
		}
		if (c) continue;
		cout << num + 1 << '\n';

	}
	return 0;
}

