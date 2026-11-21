#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans=0;
	int money; cin >> money;
	money = 1000 - money;
	ans += money / 500; money %= 500;
	ans += money / 100; money %= 100;
	ans += money / 50; money %= 50;
	ans += money / 10; money %= 10;
	ans += money / 5; money %= 5;
	ans += money / 1;;
	cout << ans;
	return 0;
}