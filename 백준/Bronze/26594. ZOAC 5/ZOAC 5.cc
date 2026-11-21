#include <iostream>
using namespace std;

int N = 1;

int main()
{
	char a;
	char b;
	cin >> a;
	while (cin>>b)
	{
		if (a == b) N++;
		else break;
	}
	cout << N;
}