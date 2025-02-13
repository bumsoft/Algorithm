#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//빌딩은 50개
//각 빌딩에 대해 선분 50번 구함, 각 선분에 대해서 닿는지 확인
// 50*50*50

// a,b => c,d로 직선: 

double arr[51];
int ans[51];

double a, b;

bool cal(int n)
{

	if (a * n + b > arr[n]) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) //지금 위치한 빌딩
	{
		for (int j = 1; j <= N; j++) //보는 빌딩
		{
			if (j == i)continue;
			//방정식
			a = ((arr[i] - arr[j]) / (i - j));
			b = (-a) * i + arr[i];
			bool ck = true;
			for (int k = min(i, j) + 1; k < max(i, j); k++) // i와 j 사이에 위치한 빌딩
			{
				ck = cal(k);
				if (!ck) break;
			}
			if (ck) 
			{ 
				ans[i]++; 
			}
		}
	}

	int answer;
	int max_ = 0;
	for (int i = 1; i <= N; i++)
	{
		max_ = max(max_, ans[i]);
	}
	cout << max_;
	return 0;
}