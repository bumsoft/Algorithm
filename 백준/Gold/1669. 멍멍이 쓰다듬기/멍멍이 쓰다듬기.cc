#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int X, Y;

// 4: 1-2-3-4-3-2-1    => 16  // 7일
// 5: 1-2-3-4-5-4-3-2-1 => 25  //9일

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> X >> Y;

	int t = Y - X;
	if (t == 0)
	{
		cout << 0; 
		return 0;
	}
	int sq = (int)sqrt(t);
	int day = sq * 2 - 1;
	int m = t - sq * sq;
	if (m == 0) cout << day;
	else if (m <= sq) cout << day + 1;
	else cout << day + 2;

}