#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[100'001];
int joint[100'001];
int N, M;

int F(int a) //루트찾기
{
	if (joint[a] == a)
	{
		return a;
	}
	int root = F(joint[a]);
	arr[root] += arr[a];
	arr[a] = 0;
	return joint[a] = root;
}

void U(int a, int b) //동맹
{
	joint[F(a)] = joint[F(b)]; //a의 루트를  b 루트에 포함시킴. => a를 b로 병력 합쳐주기
	F(a);
}

void A(int a, int b) //전쟁
{
	int aRoot = F(a);
	int bRoot = F(b);
	
	if (arr[aRoot] == arr[bRoot])
	{
		//멸망
		joint[aRoot] = -1;
		joint[bRoot] = -1;
		arr[aRoot] = 0;
		arr[bRoot] = 0;
		
	}
	else if (arr[aRoot] > arr[bRoot]) //a가 이김
	{
		arr[aRoot] -= arr[bRoot];
		arr[bRoot] = 0;
		U(aRoot, bRoot);
	}
	else //b가 이김
	{
		arr[bRoot] -= arr[aRoot];
		arr[aRoot] = 0;
		U(aRoot, bRoot);
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		joint[i] = i;
	}

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) //동맹
		{
			U(b, c);
		}
		else //전쟁
		{
			A(b, c);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0) continue;
		ans++;
	}
	cout << ans << '\n';
	sort(arr, arr + N+1);
	for (int i = 0; i <= N; i++)
	{
		if (arr[i] == 0)continue;
		cout << arr[i] << ' ';
	}
}