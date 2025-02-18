#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// A는 N의 약수이므로, 계속 정해준 구간만 주면 된다.

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, K, A, B;
	cin >> N >> K >> A >> B;

	//각 구간의 수분은 N/A 일마다 B씩 증가한다.
	// 모든 화분은 하루에 1씩 수분이 감소한다.
	
	int day = 0;
	vector<int> seg;
	int n = N / A;
	for (int i = 0; i < n; i++)
	{
		seg.push_back(K);
	}

	while (true)
	{
		seg[day % n] += B;
		for (int i = 0; i < seg.size(); i++)
		{
			seg[i]--;
			if (seg[i] == 0)
			{
				cout << day + 1;
				return 0;
			}
		}
		day++;
	}

	return 0;
}