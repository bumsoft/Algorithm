#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// X이상의 만족도를 갖는 사람이 K명 이상이 되는 최소 목소리크기
// 목소리크기:D
// i가 생각하는 적절크기 : Pi
// i의 만족도 : { (Pi - |Pi-D| ) / Pi } * 100

//만족도는?
// D>pi : (2Pi - D)/Pi * 100 = (Pi - D/pi) * 100;
// D<=pi : D/Pi * 100


// => ( (적절크기 - 차이)/적절크기 ) * 100


//각각에 대해서 만족도가 X이상이 되는 '범위'를 찾기 => 시작값, 끝값
// 모든 i에 대해서 D가 Pi일때 만족도는 100이 된다. 허용범위는 Pi (+-)A가 됨
// 100 : 70일때 70이 됨. 100일때 100.  130일때 70.  즉 70과 130
// 80 : 80일때 만족도 100.

// 절대값 >= 0인경우 : 시작값  D  = X/100*Pi
// 어차피 끝값은 (Pi + Pi-시작값) 임.  시작값만 구하면 됨. : 절대값 >=0만 구하면 됨

ll arr[100'001];


priority_queue<int> PQ1;
priority_queue<int> PQ2;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N, X, K;
	cin >> N >> X >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	// D  = X/100*Pi
	for (int i = 0; i < N; i++)
	{
		//약분은 마지막에 출력시 하자.
		ll up = arr[i] * X;//분자
		PQ1.push(-up);
		PQ2.push(-(arr[i]*200-up));
	}
	int n = 0;
	bool ck = false;
	int save;
	while (true)
	{
		if (!PQ1.empty() && !PQ2.empty())
		{
			if (-PQ1.top() <= -PQ2.top())
			{
				n++;
				save = -PQ1.top();
				if (n == K)
				{
					ck = true;
					break;
				}
				PQ1.pop();
			}
			else
			{
				n--;
				PQ2.pop();
			}
		}
		else
		{
			break;
		}
	}
	if (ck)
	{
		int l = 100;
		int low = save;
		if (low % 2 == 0) { low /= 2; l /= 2; }
		if (low % 2 == 0) { low /= 2; l /= 2; }
		if (low % 5 == 0) { low /= 5; l /= 5; }
		if (low % 5 == 0) { low /= 5; l /= 5; }
		if (l == 1)
		{
			cout << low;
		}
		else
		{
			cout << low << '/' << l;
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}