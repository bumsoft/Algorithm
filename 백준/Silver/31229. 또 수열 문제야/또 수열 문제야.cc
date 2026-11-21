#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	int t = 3;
	while (N != 0)
	{
		cout << t << ' ';
		t += 2;
		N--;
	}
	return 0;
}