#include <bits/stdc++.h>
using namespace std;

int N;
int llist[50];
int re(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (llist[n] != 0) return llist[n];
	return llist[n]=re(n - 1) + re(n - 2);
}

int main()
{
	cin >> N;
	cout << re(N);
}