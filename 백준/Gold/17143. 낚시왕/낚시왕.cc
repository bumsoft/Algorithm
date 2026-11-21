#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//뭘 하든 시간초과는 안날거같음
//순서 : 낚시왕 이동 -> 상어잡기(+잡은상어삭제) -> 상어 이동(상어끼리 먹음)
int R, C, M;

priority_queue < pair<int, pair<int, int>>> PQ[101][101];

priority_queue < pair<int, pair<int, pair<int,pair<int,int>>>>> temp; // {크기,{속도{방향{r,c}}}};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> R >> C >> M; //상어 0마리일수도
	if (M == 0) { cout << 0; return 0; }
	int r, c, s, d, z;//(r,c) 속력 방향 크기
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		PQ[r][c].push({ z,{s,d} }); // 크기, (속력,방향)
	}
	int index = 0;
	int ans = 0;
	while (true)
	{
		index++;
		for (int i = 1; i <= R; i++)
		{
			if (!PQ[i][index].empty())
			{
				ans += PQ[i][index].top().first;
			//	cout << index << "초:";//<< "누적:" << ans << '\n';
				while (!PQ[i][index].empty())PQ[i][index].pop();
				break;
			}
		}
		if (index == C)break;

		//상어이동.
		
		//모든 판을 돌면서, 상어를 temp에 넣음
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (PQ[i][j].empty())continue;
				// {크기,{속도{방향{r,c}}}};
				temp.push({ PQ[i][j].top().first,{PQ[i][j].top().second.first,{PQ[i][j].top().second.second,{i,j}}} });
				while (!PQ[i][j].empty())PQ[i][j].pop();
			}
		}
		//temp의 상어들을 이동시킨 위치에 다시 넣어줌
		int Size, To, Speed, r, c, original_Speed;
		while (!temp.empty())
		{
			Size = temp.top().first;
			original_Speed = Speed = temp.top().second.first;
			To = temp.top().second.second.first;
			r = temp.top().second.second.second.first;
			c = temp.top().second.second.second.second;
			temp.pop();
			while (true)
			{
				if (To == 1)
				{
					r -= Speed;
					if (r < 1)
					{
						Speed = 1 - r;
						To = 2;
						r = 1;
						continue;
					}
					break;
				}
				else if(To == 2)
				{
					r += Speed;
					if (r > R)
					{
						Speed = r - R;
						To = 1;
						r = R;
						continue;
					}
					break;
				}
				else if (To == 4)//왼쪽
				{
					c -= Speed;
					if (c < 1)
					{
						Speed = 1 - c;
						To = 3;
						c = 1;
						continue;
					}
					break;
				}
				else if (To == 3) //오른쪽
				{
					c += Speed;
					if (c > C)
					{
						Speed = c - C;
						To = 4;
						c = C;
						continue;
					}
					break;
				}
			}
			//크기, (속력, 방향)
			PQ[r][c].push({Size,{original_Speed,To}});
			//cout << "(" << r << "," << c << ")size:" << Size << '\n';
		}
	}
	cout << ans;

	return 0;
}