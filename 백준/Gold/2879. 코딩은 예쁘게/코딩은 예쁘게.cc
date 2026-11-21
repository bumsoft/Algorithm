#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int diff[1'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> diff[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		diff[i] = temp - diff[i];
	}

	int ans = 0;
	bool ck = false;
	while (true)
	{
		if (ck) break;

		int direction = 0;
		ck = true;
		for (int i = 0; i < N; i++)
		{
			if (diff[i] != 0)ck = false;
			if (direction==1 && diff[i] > 0) //+ -> +
			{
				diff[i]--;
				continue;
			}
			if (direction == 1 && diff[i] < 0)//+ -> -
			{
				diff[i]++;
				direction = -1;
				ans++;
				continue;
			}
			if (direction == 1 && diff[i] == 0)//+ -> 0
			{
				direction = 0;
				continue;
			}
			
			if (direction == -1 && diff[i] < 0) //- -> -
			{
				diff[i]++;
				continue;
			}
			if (direction == -1 && diff[i] > 0) //- -> +
			{
				diff[i]--;
				ans++;
				direction = 1;
			}
			if (direction == -1 && diff[i] == 0) // - -> 0
			{
				direction = 0;
				continue;
			}

			if (direction == 0 && diff[i] > 0) // 0 -> +
			{
				ans++;
				diff[i]--;
				direction = 1;
				continue;
			}
			if (direction == 0 && diff[i] < 0 ) // 0 -> -
			{
				ans++;
				diff[i]++;
				direction = -1;
				continue;
			}
			if (direction == 0 && diff[i] == 0) // 0 -> 0
			{
				continue;
			}
		}
	}
	cout << ans;

	return 0;
}