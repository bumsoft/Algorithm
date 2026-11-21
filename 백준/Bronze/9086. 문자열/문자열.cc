#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	string a;
	while (T--)
	{
		cin >> a;
		cout << a[0] << a[a.length() - 1] << '\n';
	}
	return 0;
}