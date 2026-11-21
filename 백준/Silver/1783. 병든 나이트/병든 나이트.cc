//4번 이상 이동하는경우 모두 한번씩은 사용
//3번 이하인 경우 ㄱㅊ


#include <bits/stdc++.h>
#define min(a,b) a>b ? b:a
using namespace std;

int N, M;
int ans;
int main()
{
	cin >> N >> M;
	//3이하
	if (N == 1)
	{
		ans = 1;
	}
	else if (N == 2)
	{
		ans = min(4, (M + 1) / 2);
	}
	else if(M<7)
	{
		ans = min(4, M);
	}
	//4이상
	else
	{
		ans = M - 2;
	}
	cout << ans;

	return 0;
}