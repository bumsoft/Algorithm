#include <bits/stdc++.h>
using namespace std;
int main()
{
	queue<int> m;
	stack<int> p;
	vector<int> v;
	int t;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0)
		{
			m.push(v[i]);
		}
		else
		{
			p.push(v[i]);
		}
	}
	int ans = 0;
	if (m.empty())
	{
		ans+= p.top();
		p.pop();
		for (int i = 0; i < M-1; i++)
		{
			if (!p.empty())p.pop();
		}
		while (!p.empty())
		{
			for (int i = 0; i < M; i++)
			{
				if (!p.empty())
				{
					if (i == 0)
					{
						ans += 2*p.top();
					}
					p.pop();
				}
			}
		}
	}
	else if (p.empty())
	{
		ans += abs(m.front());
		m.pop();
		for (int i = 0; i < M-1; i++)
		{
			if (!m.empty())m.pop();
		}
		while (!m.empty())
		{
			for (int i = 0; i < M; i++)
			{
				if (!m.empty())
				{
					if (i == 0)
					{
						ans += 2*abs(m.front());
					}
					m.pop();
				}
			}
		}
	}
	else
	{
		if (p.top() >= abs(m.front()))
		{
			ans += p.top();
			p.pop();
			for (int i = 0; i < M - 1; i++)
			{
				if (!p.empty())p.pop();
			}
		}
		else
		{
			ans += abs(m.front());
			m.pop();
			for (int i = 0; i < M - 1; i++)
			{
				if (!m.empty())m.pop();
			}
		}
		while (!p.empty())
		{
			for (int i = 0; i < M; i++)
			{
				if (!p.empty())
				{
					if (i == 0)
					{
						ans += 2 * p.top();
					}
					p.pop();
				}
			}
		}
		while (!m.empty())
		{
			for (int i = 0; i < M; i++)
			{
				if (!m.empty())
				{
					if (i == 0)
					{
						ans += 2 * abs(m.front());
					}
					m.pop();
				}
			}
		}
	}
	cout << ans;
	return 0;
}