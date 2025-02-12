#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1. 반으로 자름.
//2. 자른 것의 가운데의 수가 101010 또는 010101꼴인지 확인

//3. 1~2 반복 => 더이상 안잘릴때까지.

// 100 0 110
//  0     1 로 다름
// 1 0   1 0  가능

queue<int> Q;

void init()
{
	while (!Q.empty())
	{
		Q.pop();
	}
}

bool check()
{
	if (Q.size() == 1) return true;

	int s = Q.front();
	Q.pop();
	while (!Q.empty())
	{
		if (s == Q.front())
		{
			return false;
		}
		s = Q.front();
		Q.pop();
	}
	return true;
}

// 0~6
// 0~2 4~6

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	string s;
	while (T--)
	{
		cin >> s;
		init();
		bool ans = true;
		if (s.length() == 1)
		{
			cout << "YES\n";
			continue;
		}
		priority_queue<pair<int, pair<int, int>>> PQ; // start에 따른 pop순서 조정필요 => -start로 넣기!
		PQ.push({ 0,{0, s.length()-1} });
		int pre = 0;
		while (!PQ.empty()) //depth순, start가 작은 순으로 꺼내야함.
		{
			int depth = -PQ.top().first;
			int start = -PQ.top().second.first;
			int e = PQ.top().second.second;
			PQ.pop();

			if (pre != depth)
			{
				ans = check();
				if (!ans) {
					PQ.push({ 0,{0,0} });
					break;
				}
				init();
				pre = depth;
			}

			if (start == e) 
			{
				Q.push(s[start]); 
				continue;
			}

			//가운데 값을 Q에 넣고, 반으로 쪼개서 PQ에 넣기
			Q.push(s[(start + e) / 2]);
			PQ.push({ -(depth + 1),{-(start), (start + e) / 2 - 1} });
			PQ.push({ -(depth + 1),{-((start + e) / 2 + 1), e } });
		}
		if (PQ.empty())ans = check();
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	


	return 0;
}