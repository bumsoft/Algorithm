#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, T, P, ans, timee = 540;
bool sit[101];
int left_time[101];
queue<pair<int, int>> Q; //시작시간/이용시간
vector<pair<int, int>> V; //임시
priority_queue<int> pq;
int	sit_where() //어디 앉을 지 반환
{
	vector<int> v;
	int arr[101];
	for (int i = 0; i < N; i++)
	{
		if (sit[i])v.push_back(i);
	}
	if (v.size() == 0)return 0;

	for (int i = 0; i < N; i++)
	{
		if (sit[i])continue;
		int low = 100; //왼쪽으로 부터 공간
		int high = 100; //오른쪽으로 부터 공간
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] < i)low = i-v[j]-1;
			else if (v[j] > i)
			{
				high = v[j] - i - 1;
				break;
			}
		}
		arr[i] = min(high, low);
	}
	int m = -1, save = -1;
	for (int i = 0; i < N; i++)
	{
		if (sit[i])continue;
		if (arr[i] > m)
		{
			m = arr[i];
			save = i;
		}
	}
	return save;
}

void reduce_time()
{
	for (int i = 0; i < N; i++)
	{
		if (sit[i])
		{
			left_time[i]--;
			if (left_time[i] <= 0)sit[i] = false;
		}
	}
}
void show_p()
{
	cout << timee/60<<':'<<timee%60<<"좌석현황:";
	for (int i = 0; i < N; i++)
	{
		if (sit[i])cout << i+1 << ',';
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, ta, tb;
	string a, b;
	cin >> N >> T >> P;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		ta = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(2, 4));
		tb = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(2, 4));
		V.push_back(make_pair(ta, tb - ta));
	}
	sort(V.begin(), V.end());
	t = V[0].first;
	pq.push(-V[0].second);

	for (int i = 1; i < V.size(); i++)
	{
		if (t == V[i].first)
		{
			pq.push(-V[i].second);
		}
		else
		{
			while (!pq.empty())
			{
				Q.push(make_pair(t, -pq.top()));
				pq.pop();
			}
			t = V[i].first;
			pq.push(-V[i].second);
		}
	}
	while (!pq.empty())
	{
		Q.push(make_pair(t, -pq.top()));
		pq.pop();
	}
	for (timee; timee < 1260; timee++)
	{

		reduce_time();

		while (!Q.empty())
		{
			if (Q.front().first == timee)
			{
				t = sit_where();
				if (Q.front().second == 0)
				{
					Q.pop();
				}
				else
				{
					left_time[t] = Q.front().second;
					sit[t] = true;
					Q.pop();
				}
			}
			else
			{
				break;
			}
		}
		//show_p();
		if (!sit[P-1]) ans++;
	}
	cout << ans;

	return 0;
 }