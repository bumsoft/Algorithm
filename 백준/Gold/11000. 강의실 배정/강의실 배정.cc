#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N;
	int s, e;
	priority_queue<pair<int, int>> PQ;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		PQ.push({ -s,e });
	}

	priority_queue<int> PQ2; //각 강의실의 끝나는 시간
	PQ2.push(0);
	
	while (!PQ.empty())
	{
		int eTime = PQ.top().second;
		int sTime = -PQ.top().first;
		PQ.pop();
		if (-PQ2.top() > sTime)
		{
			PQ2.push(-eTime);
		}
		else
		{
			PQ2.pop();
			PQ2.push(-eTime);
		}
	}
	cout << PQ2.size();
	return 0;
}