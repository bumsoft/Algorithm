#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == 0) return 0;
		if (a > b) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}