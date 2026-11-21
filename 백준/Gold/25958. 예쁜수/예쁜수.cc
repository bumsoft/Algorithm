//구성이 달라야함

//M이하의 예쁜수를 구하고 예쁜수들로 dp?

#include <bits/stdc++.h>
using namespace std;
int M, K;
int mem[5001];
vector<int> v;
bool vis[5001];

bool num(int m)
{
	int sum = 0, n = m;
	while (n!=0)
	{
		sum += n % 10;
		n /= 10;
	}
	if (m % sum == 0) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> M >> K;
	for (int i = 1; i <= M; i++)
	{
		if (num(i)) { v.push_back(i); }
	}
	mem[0] = 1;
	for (int t : v)
	{
		for (int i = 0; i < M + 1; i++)
		{
			if (t <= i) 
			{ 
				mem[i] += mem[i - t]%K;
				mem[i] %= K;

			}
		}
	}

	cout << mem[M]%K;

	return 0;
}