#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
vector<int> first;
vector<int> last;

void order(int n, int now, int checkpoint, int target)
{
	if (n == 1)
	{
		first.push_back(now);
		last.push_back(target);
		cnt++;
		return;
	}
	//N-1까지를 두번째에 옮김
	cnt++;
	order(n - 1, now, target, checkpoint);
	first.push_back(now);
	last.push_back(target);
	order(n - 1, checkpoint, now, target);
	

}

int main()
{
	cin >> N;
	order(N, 1, 2, 3);
	cout << cnt << '\n';
	for (int i = 0; i < first.size(); i++)
	{
		cout << first[i] << ' ' << last[i] << '\n';
	}
}