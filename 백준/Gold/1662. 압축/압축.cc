#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string t; cin >> t;
	stack<ll> st; // ')'가 나올때마다 0push
	for (int i = t.length() - 1; i >= 0; i--)
	{
		if (t[i] == ')')
		{
			st.push(-1);
		}
		else if (t[i] == '(')
		{
			ll temp = 0;
			while (st.top() != -1)
			{
				temp += st.top();
				st.pop();
			}
			st.pop(); //-1지움

			st.push(temp * (t[--i]-'0'));
		}
		else
		{
			ll temp;
			if (st.empty())
			{
				temp = 0;
			}
			else 
			{
				if (st.top() == -1)
				{
					temp = 0;
				}
				else
				{
					temp = st.top();
					st.pop();
				}
			}
			st.push(temp + 1);
		}
	}
	ll ans = 0;
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	cout << ans << '\n';
	return 0;
}