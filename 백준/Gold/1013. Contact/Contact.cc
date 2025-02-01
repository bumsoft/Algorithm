#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int trans[10][2] =
{
	{0,0},
	{2,4},
	{0,3},
	{2,4},
	{5,0},
	{6,0},
	{6,7},
	{2,9},
	{6,3},
	{8,9}
};
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	string s;
	while (N--)
	{
		cin >> s;
		int loc = 1;
		for (int i = 0; i < s.size(); i++)
		{
			loc = trans[loc][s[i] - 48];
		}
		if (loc == 3 || loc == 7 || loc == 9) cout << "YES\n";
		else cout << "NO\n";
	}
}