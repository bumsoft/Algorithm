#include <bits/stdc++.h>
using namespace std;

int dx[] = { 2,2,-2,-2 ,1,1,-1,-1};
int dy[] = { 1,-1,1,-1,2,-2,2,-2 };
int ans;



int T, l;
int x, y;
int tx, ty;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		queue<int> xx;
		queue<int> yy;
		queue<int> m;
		int visit[301][301]{};
		cin >> l;
		cin >> x >> y >> tx >> ty;
		xx.push(x); yy.push(y); m.push(0);
		visit[x][y]++;
		while (true)
		{
			int nx = xx.front();  xx.pop();
			int ny = yy.front(); yy.pop();
			
			int t = m.front(); 

			if (nx == tx && ny == ty) break;
			m.pop();
			
			for (int i = 0; i < 8; i++)
			{
				if (nx + dx[i] >= 0 && nx + dx[i] < l)
				{
					if (ny + dy[i] >= 0 && ny + dy[i] < l)
					{
						if (visit[nx+dx[i]][ny+dy[i]]==0)
						{
							xx.push(nx + dx[i]); yy.push(ny + dy[i]);
							m.push(t + 1);
							visit[nx + dx[i]][ny + dy[i]]++;
						}
					}
				}
			}
		}
		cout << m.front() << '\n';
	}
	return 0;
}