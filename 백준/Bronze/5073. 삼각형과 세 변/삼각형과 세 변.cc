#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0) return 0;

		if (max({ a, b, c }) >= a + b + c - max({ a, b, c })) { cout << "Invalid\n"; continue; }
		if (a == b && b == c) { cout << "Equilateral\n"; continue; }
		if (a != b && b != c && a != c) { cout << "Scalene\n"; continue; }
		else cout << "Isosceles\n";
	}
	return 0;
}