#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 선플레이어=>후플레이어
// 0~N-1까지의 번호가 부여된 점 N개 주어짐
// 어느 세 점도 일직선 위에 놓이지 않음
// 매 턴, 두 점을 잇는다. 중복 x
// 사이클 완성시 종료

int N;
ll arr[5001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);
	vector<ll> a;
	ll o;
	ll ans = LLONG_MAX;
	for (int i = 0; i < N; i++)
	{
		o = arr[i];
		// i 번째 고정
		// i를 제외한 다른 abs(두 용액의 합 + arr[i])의 최소값을 찾는다.
		for (int j = 0; j < N; j++)
		{
			if (j == i)continue;
			// o + arr[j] + K == 0 인 K를 찾기
			// K == -(o+arr[j]) 여야함
			// 만약 둘의 합이 30이라면 -30에 가장 가까운 걸 찾아야한다.
			int index = lower_bound(arr, arr + N, -(o + arr[j])) - arr;

			//찾은 index가 i j면 안된다.
			if (index != i && index != j && index - 1 != i && index - 1 != j)
			{
				if (index == N)
				{
					if (abs(o + arr[j] + arr[index - 1]) < ans)
					{
						ans = abs(o + arr[j] + arr[index - 1]);
						a.clear();
						a.push_back(o);
						a.push_back(arr[j]);
						a.push_back(arr[index - 1]);
					}
					continue;
				}
				if (o + arr[j] + arr[index] == 0)
				{
					priority_queue<ll> pq;
					pq.push(-o); pq.push(-arr[j]); pq.push(-arr[index]);
					cout << -pq.top() << ' ';
					pq.pop();
					cout << -pq.top() << ' ';
					pq.pop();
					cout << -pq.top();
					return 0;
				}
				if (abs(o + arr[j] + arr[index]) < ans)
				{
					ans = abs(o + arr[j] + arr[index]);
					a.clear();
					a.push_back(o);
					a.push_back(arr[j]);
					a.push_back(arr[index]);
				}

				if (index != 0 && abs(o + arr[j] + arr[index - 1]) < ans)
				{
					ans = abs(o + arr[j] + arr[index - 1]);
					a.clear();
					a.push_back(o);
					a.push_back(arr[j]);
					a.push_back(arr[index - 1]);
				}
			}
			else
			{
				while (index == i || index == j || index - 1 == i || index - 1 == j)
				{
					index--;
				}
				if (index < 0)continue;
				if (o + arr[j] + arr[index] == 0)
				{
					priority_queue<int> pq;
					pq.push(o); pq.push(arr[j]); pq.push(arr[index]);
					cout << pq.top() << ' ';
					pq.pop();
					cout << pq.top() << ' ';
					pq.pop();
					cout << pq.top();
					return 0;
				}
				if (abs(o + arr[j] + arr[index]) < ans)
				{
					ans = abs(o + arr[j] + arr[index]);
					a.clear();
					a.push_back(o);
					a.push_back(arr[j]);
					a.push_back(arr[index]);
				}
			}
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}