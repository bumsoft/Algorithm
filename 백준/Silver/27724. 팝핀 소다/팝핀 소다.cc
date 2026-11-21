#include <bits/stdc++.h>
using namespace std;

//N명의 선수(2의 거듭제곱)
//각 선수는 탄산내성(1~N) 중복x
//두명씩 짝지어 대결 => N/2번의대결   => 패자 빼고 다시 반복
//탄산내성 높은사람이 승
//이변이 일어나면 반대.
//시은이가 승리할수있는 대결이 최대 몇?

int N, M, K; //수, 이변, 내성

int main()
{
	cin >> N >> M >> K;
	int low = K;
	int high = N - low;
	int ans = 0;
	//어차피 low+high는 짝수임:하나가 홀수라면 나머지도 홀수다.

	while (low/2!=0 && high/2!=0)
	{
		ans++;
		low /= 2;
		high /= 2;
	} //빠져나왔으면 하나가 1이 되었단 소리
	if (low == 1) //본인
	{
		while (high != 1 && M!=0)
		{
			high /= 2;
			ans++;
			M--;
		}
		if (high == 1 && M!=0) //둘 다 1인경우 여기서 처리됨
		{
			ans++;
		}
	}
	else //high==1
	{
		while (low != 1)
		{
			low /= 2;
			ans++;
		}
		if (low==1&&high==1&&M != 0)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}