#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> Nlist(1048577);

int main()
{
	int N, n;
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Nlist[i];
	}
////////end input
	
	cin >> n;
	int k = N / n; //몇개씩 정렬?
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		sort(Nlist.begin()+start, Nlist.begin()+start+k);
		start += k;
	}
	for (int i = 0; i < N; i++)
	{
		cout << Nlist[i] << ' ';
	}
}