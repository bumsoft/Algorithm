#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//몬스터는 최대 10만
//팁은 최대 30만개=> 하나의 몬스터를 잡을때 난이도를 결정하는 아이템이 여러개가 존재할 수 있다!! = require를 저장하는 걸 조금 수정해야할 것 같음!

ll ans;
ll arr[100'001]; //몬스터의 난이도
bool is_tip[100'001]; //이 몬스터에 팁이 존재하는지 -> 존재한다면 require확인하기
vector<pair<ll,ll>> require[100'001]; // 이 아이템으로 잡는 몬스터 / 달라지는 난이도
bool vis[100'001]; //잡은 몬스터인지

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;

	priority_queue<pair<ll,ll>> PQ; // <난이도, 번호>
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int P;
	cin >> P;
	int a, b, c;
	for (int i = 0; i < P; i++)
	{
		cin >> a >> b >> c;
		arr[b] += c; //b몬스터 난이도 c만큼 증가시킴
		is_tip[a] = true; //a아이템에 대한 팁이 존재한다
		require[a].push_back(make_pair(b,c)); //b몬스터는 a아이템이 필요하며, 없으면 난이도는 c만큼 증가함
	}
	for (int i = 1; i <= N; i++)
	{
		PQ.push(make_pair(-arr[i],i));
	}

	ll temp, num;
	while (M)
	{
		temp = -PQ.top().first;
		num = PQ.top().second;
		PQ.pop();
		if (vis[num])continue;
		vis[num] = true;
		M--;
		//cout << num << ',' << "난이도:" << temp << endl;
		if (is_tip[num]) //num번 아이템 팁이 존재하는 경우
		{
			for (int i = 0; i < require[num].size(); i++)
			{
				arr[require[num][i].first] -= require[num][i].second;
				PQ.push(make_pair(-arr[require[num][i].first], require[num][i].first));
			}
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
 }