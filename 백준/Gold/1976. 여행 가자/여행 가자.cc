#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[201];

int F(int a)
{
	if (arr[a] == a) return a;
	else return arr[a] = F(arr[a]);
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) arr[i] = i;

	int t;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> t;
			if (j <= i)continue;
			if (t == 1)
			{
				//i와 j union
				arr[F(i)] = F(j);
			}
		}
	}

	int pre; cin >> pre;
	for (int i = 1; i < M; i++)
	{
		cin >> t;
		if (F(pre) == F(t)) pre = t;
		else {cout << "NO"; return 0;}
	}
	cout << "YES";
	return 0;
}