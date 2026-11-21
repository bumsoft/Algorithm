#include <bits/stdc++.h>
using namespace std;
//혼합한 용액의 특성값: 사용된 용액의 특성값의 합;
//0에 가장 가까운 용액 만들기
int N;
int arr[100'001];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];

	int a = 0, b = N - 1;
	int as = 0, bs = N - 1;
	int temp;
	int mi = abs(arr[a] + arr[b]);
	
	while (a < b) {
		temp = arr[a] + arr[b];
		if (abs(temp) < mi) {
			mi = abs(temp);
			as = a;
			bs = b;
		}

		if (temp < 0) {
			a++;
		}
		else {
			b--;
		}
	}
	cout << arr[as] << ' ' << arr[bs];

	return 0;
}