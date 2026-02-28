#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int T;

int D[1001];

int dp[1001]; //dp[i] : i건물을 지을 때 필요한 최대 시간
// i전에 지어야 하는 것이 a,b라고 할 때,
// dp[i] = D[i] + max(dp[a],dp[b]); => 이걸 위해서 a,b를 미리 구해야하나?
// 진입차수가 0인 모든 부분을 큐에 넣고 시작하기. 아직 이전 건물이 지어지지 않은 경우, 다시 큐 뒤로 보내기

vector<int> nodes_in[1001];
vector<int> nodes_out[1001];

int in_cnt[1001];
//int out_cnt[1001];

void init(int N)
{
	for (int i = 1; i <= N; i++)
	{
		dp[i] = INT_MAX;
		nodes_in[i].clear();
		nodes_out[i].clear();
		in_cnt[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N, K, W;
		cin >> N >> K;

		init(N);

		for (int i = 1; i <= N; i++)
		{
			cin >> D[i];
		}
		int X, Y;
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y; // X -> Y
			nodes_in[Y].push_back(X);
			nodes_out[X].push_back(Y);
			in_cnt[Y]++;
			//out_cnt[X]++;
		}
		cin >> W;
		queue<int> Q; //<node>
		for (int i = 1; i <= N; i++)
		{
			if (in_cnt[i] == 0)
			{
				Q.push(i);
			}
		}
		while (!Q.empty()) // 진입차수가 0(완료)된 것만 큐에 들어옴
		{
			int max_time = 0;
			int now = Q.front();

			for (int i = 0; i < nodes_in[now].size(); i++)
			{
				max_time = max(max_time, dp[nodes_in[now][i]]);
			}
			Q.pop();
			dp[now] = max_time + D[now];

			if (now == W)
			{
				cout << dp[now] << '\n';
				break;
			}

			//다음 건물
			for (int i = 0; i < nodes_out[now].size(); i++)
			{
				in_cnt[nodes_out[now][i]]--;
				if(in_cnt[nodes_out[now][i]] == 0)
					Q.push(nodes_out[now][i]);
			}
		}
	}
	return 0;
}
