#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 수를 기록하는 회의실 배정 -> 그리디
int ans[100'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> users;
	int P, Q;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> Q;
		users.push_back({ P,Q });
	}
	sort(users.begin(), users.end());

	int computer = 1;

	priority_queue<int> C; // 비어있는 컴퓨터

	priority_queue<pair<int, int>> PQ; // <끝나는 시간, 컴퓨터번호>
	PQ.push({ -users[0].second, 1 });
	ans[1]++;

	for (int i = 1; i < N; i++)
	{
		int s_time = users[i].first;
		int e_time = users[i].second;

		while (!PQ.empty())
		{
			if (s_time >= -PQ.top().first)
			{
				C.push(-PQ.top().second);
				PQ.pop();
			}
			else break;
		}
		if (!C.empty())
		{
			PQ.push({ -e_time, -C.top() });
			ans[-C.top()]++;
			C.pop();
		}
		else
		{
			computer++;
			PQ.push({ -e_time, computer });
			ans[computer]++;
		}
	}
	cout << computer << '\n';
	for (int i = 1; i <= computer; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}