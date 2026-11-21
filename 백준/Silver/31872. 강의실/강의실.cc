#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int compare(int a, int b)
{
	return a > b;
}


int N, K;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	vector<int> distance;
	for (int i = 0; i < N; i++)
	{
		int temp = v[i + 1] - v[i];
		distance.push_back(temp);
	}

	sort(distance.begin(), distance.end(),compare);
	for (int i = 0; i < N; i++)
	{
		//cout << distance[i];
	}
	int sum = 0;
	for (int i = K; i < N; i++)
	{
		sum += distance[i];
	}

	cout << sum;
	return 0;
}