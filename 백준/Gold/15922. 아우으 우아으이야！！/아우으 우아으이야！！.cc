#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// -5   -2
//   -3      0
//              2     5
//                      6        10
//                         8         12
// 2 1  = 3
int N;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	N--;
	int start;
	int preEnd;
	int r = 0;
	int a, b;
	cin >> start >> preEnd;
	while (N--)
	{
		cin >> a >> b;
		if (preEnd >= a)
		{
			if (preEnd > b) continue;
			else preEnd = b;
		}
		else
		{
			r += a - preEnd;
			preEnd = b;
		}
	}
	cout << preEnd - start - r;
	

	return 0;
}