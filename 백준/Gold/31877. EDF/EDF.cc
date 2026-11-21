#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using A = pair<ll, ll>;
using B = pair < ll, pair<ll, ll>>;

struct cmp1 {
	bool operator()(A a, A aa) { // <마감시각, 소요시각>
		if (a.first == aa.first)
		{
			return a.second > aa.second;
		}
		return a.first > aa.first;
	}
};
struct cmp2 {
	bool operator()(B b, B bb) { // 추가시각
		return b.first > bb.first;
	}
};

priority_queue<A, vector<A>,cmp1> PQ1;
priority_queue<B, vector<B>, cmp2> PQ2; //얘는 그냥 추가시간 빠른순으로 뽑기
int N, M;
ll w, t, d;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t >> d;
		PQ1.push({ d,t });
		
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> w >> t >> d;
		PQ2.push({ w,{d,t} });
	}
	//while (!PQ2.empty())
	//{
	//	cout << PQ2.top().first;
	//	cout << PQ2.top();
	//	cout << PQ2.top();
	//}
	ll time = 0;
	
	while (!PQ1.empty())
	{
		//추가되는 작업여부 확인
		if (PQ2.empty())
		{
			if (time + PQ1.top().second > PQ1.top().first)
			{
				cout << "NO";
				return 0;
			}
			auto temp = PQ1.top();
			PQ1.pop();
			time += temp.second;
			continue;
		}

		//초과 안났는지 확인
		if (time + PQ1.top().second > PQ1.top().first)
		{
			cout << "NO"; 
			return 0;
		}

		if (time + PQ1.top().second > PQ2.top().first) //현재 작업끝나는 시간 전에 작업 추가
		{
			auto temp = PQ1.top();
			PQ1.pop();

			ll diff = PQ2.top().first - time;  //추가되는 시간까지의 차, 즉 pq1의 작업가능한 시간
			time += diff;
			PQ1.push({temp.first, temp.second-diff}); //?
			PQ1.push(PQ2.top().second);
			PQ2.pop();
		}
		else if (time + PQ1.top().second == PQ2.top().first) //끝나자마자 추가되는 경우
		{
			time += PQ1.top().second;
			PQ1.pop();
			PQ1.push(PQ2.top().second);
			PQ2.pop();
		}
		else //현재작업 끝내기 가능
		{
			time += PQ1.top().second;
			PQ1.pop();
		}

		if (PQ1.empty() && !PQ2.empty())//추가할 작업만 남은 경우
		{
			if (PQ2.top().first >= time)
			{
				time = PQ2.top().first;
				PQ1.push(PQ2.top().second);
				PQ2.pop();
			}
		}

	}

	cout << "YES\n" << time;
	return 0;
}