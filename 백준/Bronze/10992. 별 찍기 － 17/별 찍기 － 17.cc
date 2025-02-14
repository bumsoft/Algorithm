#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= 2*n-1; j++)
		{
			if (n - i + 1 == j) cout << '*';
			else if (n + i - 1 == j) cout << '*';
			else if (j < n + i - 1) cout << ' ';
			else break;
		}
		cout << '\n';
	}
	for (int i = 0; i < 2*n -1; i++)
	{
		cout << '*';
	}
}