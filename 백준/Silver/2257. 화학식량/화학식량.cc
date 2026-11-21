#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//H : 1  
//C : 12 
//O : 16

char str[101];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> str;
	stack<int> ST;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
		{
			ST.push(-1);
		}
		else if (str[i] == ')')
		{
			int temp = 0;
			while (ST.top() != -1)
			{
				temp += ST.top();
				ST.pop();
			}
			ST.pop(); ST.push(temp);
		}
		else if (str[i] >= '2' && str[i] <= '9')
		{
			int temp = ST.top();
			ST.pop();
			ST.push(temp * (str[i] - '0'));
		}
		else
		{
			if (str[i] == 'H')
			{
				ST.push(1);
			}
			else if (str[i] == 'C')
			{
				ST.push(12);
			}
			else
			{
				ST.push(16);
			}
		}
	}
	int ans = 0;
	while (!ST.empty())
	{
		ans += ST.top();
		ST.pop();
	}
	cout << ans;
}