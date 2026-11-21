#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int llist[501][2555];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int l = 1;
	int num_list;
	int num_candidate;
	while (true)
	{
		cin >> num_list >> num_candidate;
		if (num_list == 0)return 0;
		int t;
		//       0번 2번 3번 4번 ...2499번
		//투표자1 등수등수등수등수
		//투표자2   ""
		//투표자3   ""
		// 500

		for (int i = 0; i < num_list; i++)
		{
			for (int j = 0; j < num_candidate; j++) //등수
			{
				cin >> t;
				llist[i][t] = j;
			}
		}
		int ans = 0;
		for (int i = 1; i < num_candidate; i++)
		{
			int w_ans = 0, w_i = 0;
			for (int j = 0; j < num_list; j++)
			{
				if (llist[j][ans] < llist[j][i])
				{
					w_ans++;
				}
				else w_i++;
			}
			ans = w_ans > w_i ? ans : i;
		}
		//ans보다 뒤에있는 후보자들은 ans를 못이김=> 한번이라도 못이기면 승자 x
		//0~ ans전까지 비교
		bool ck = true;
		for (int i = 0; i < ans; i++)
		{
			int w_ans = 0, w_i = 0;
			for (int j = 0; j < num_list; j++)
			{
				if (llist[j][ans] < llist[j][i])
				{
					w_ans++;
				}
				else w_i++;
			}
			if (w_ans <= w_i) { ck = false; break; }
		}
		cout << "Case " << l++ << ": ";
		if (ck)
		{
			cout << ans << '\n';
		}
		else cout << "No Condorcet winner\n";
	}
	return 0;
}