#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int tNum;
bool truth[51];
vector<int> party[51];
bool party_truth[51];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	cin >> tNum;
	int t;
	for (int i = 0; i < tNum; i++)
	{
		cin >> t;
		truth[t] = true;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> tNum;
		for (int j = 0; j < tNum; j++)
		{
			cin >> t;
			party[i].push_back(t);
		}
	}
	int T = 0;
	while (true)
	{
		int bT = T;
		for (int i = 0; i < M; i++) //각 파티에 대해
		{
			if (party_truth[i]) continue;
			for (int j = 0; j < party[i].size(); j++)
			{
				if (truth[party[i][j]])
				{
					party_truth[i] = true;
				}
			}
			if (party_truth[i])
			{
				T++;
				for (int j = 0; j < party[i].size(); j++)
				{
					truth[party[i][j]] = true;
				}
			}
		}
		if (bT == T) break;
	}
	cout << M - T;

	//1. 진실을 아는 사람이 있는 파티의 모든 사람은 진실을 알게 된다.
	//2. 
}