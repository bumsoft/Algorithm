#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int E, S, M; cin >> E >> S >> M;
	for (int i = 1;; i++)
	{
		if ((i % 15 == E || i%15==0&&E==15) 
			&& (i % 28 == S||i%28==0&&S==28) 
			&& (i % 19 == M || i%19==0&&M==19))
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}