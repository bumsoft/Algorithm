#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int arr[2444];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> arr[i];
	}
	sort(arr, arr + N);
	cout << arr[N - 1] - arr[0];
	return 0;
}