#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool fr[51][51];
int N;
string arr[51];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// i의 j번사람 친구여부
			if (arr[i][j] == 'Y') //친구면?
			{
				fr[i][j] = true;
				for (int k = 0; k < N; k++)
				{
					if (arr[j][k] == 'Y')
					{
						fr[i][k] = true;
					}
				}
			}
		}
		fr[i][i] = false;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (fr[i][j]) cnt++;
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
}

