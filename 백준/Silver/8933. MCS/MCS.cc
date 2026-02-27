#include <bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--)
	{
		unordered_map<string, int> m;
		int k;
		string W;
		cin >> k >> W;

		int AA = 0;
		int GG = 0;
		int TT = 0;
		int CC = 0;
		for (int i = 0; i < k; i++)
		{
			if (W[i] == 'A') AA++;
			else if (W[i] == 'G') GG++;
			else if (W[i] == 'T') TT++;
			else CC++;
		}
		string t = to_string(AA) + ":" + to_string(GG) + ":" + to_string(TT) + ":" + to_string(CC);
		m[t]++;
		int max_cnt = 1;

		for (int i = 1; i + k <= W.size(); i++)
		{
			if (W[i-1] == 'A') AA--;
			else if (W[i-1] == 'G') GG--;
			else if (W[i-1] == 'T') TT--;
			else CC--;
			if (W[i+k-1] == 'A') AA++;
			else if (W[i + k - 1] == 'G') GG++;
			else if (W[i + k - 1] == 'T') TT++;
			else CC++;

			string t = to_string(AA) + ":"+ to_string(GG) + ":" + to_string(TT) + ":" + to_string(CC);
			max_cnt = max_cnt < ++m[t] ? m[t] : max_cnt;
		}
		cout << max_cnt << '\n';
	}

	return 0;
}
