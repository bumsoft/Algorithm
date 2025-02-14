#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 집합 S 두 원소의 합이 K와 가장 가까운 경우의 개수
// 2<= |S| <= 1'000'000
// -10^8 <= K <= 10^8

//O(N)정도로 풀어야 할 듯 => 투포인터??

// -7 -4 -3 -2 0 1 2 5 9 12


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, K; cin >> n >> K;
		vector<int> S;
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			S.push_back(temp);
		}
		sort(S.begin(), S.end());

		int s = 0;
		int e = n - 1;

		int diff = INT_MAX;
		int cnt = 0;
		while (s < e)
		{
			int sum = S[s] + S[e];
			if (abs(K - sum) < diff)
			{
				cnt = 1;
				diff = abs(K - sum);
			}
			else if (abs(K - sum) == diff)
			{
				cnt++;
			}

			if (sum < K)
			{
				s++;
			}
			else
			{
				e--;
			}
		}
		cout << cnt << '\n';
	}

}