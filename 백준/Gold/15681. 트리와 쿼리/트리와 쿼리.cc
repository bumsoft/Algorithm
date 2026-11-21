#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> temp_tree[200'001];
vector<int> real_tree[200'001];
int number_of_s_tree[200'001]; //노드별 자식(후손)수를 저장할 배열 -> 모든 리프노드에서 루트로 가면서 구해야함
int N, root;
bool vis[200'001];
queue<int> Q;



int search_s(int node)
{
	if (real_tree[node].size() == 0) //리프면
	{
		return number_of_s_tree[node];//0
	}
	int sum = 0;
	for (int i = 0; i < real_tree[node].size(); i++)
	{
		sum += search_s(real_tree[node][i]);
	}
	sum += real_tree[node].size();
	return number_of_s_tree[node] = sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Qq;
	cin >> N >> root >> Qq;
	int a, b;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		temp_tree[a].push_back(b);
		temp_tree[b].push_back(a);
	}
	//bfs로 순서 찾기
	Q.push(root);
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		vis[node] = true;
		for (int i = 0; i < temp_tree[node].size(); i++)
		{
			if (!vis[temp_tree[node][i]])
			{
				Q.push(temp_tree[node][i]);
				real_tree[node].push_back(temp_tree[node][i]);
			}
		}
	}
	search_s(root);
	int q;
	while (Qq--)
	{
		cin >> q;
		cout << number_of_s_tree[q]+1 << '\n';
	}
	return 0;
}