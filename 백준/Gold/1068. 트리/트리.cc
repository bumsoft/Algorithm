#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

vector<int> child[51];
int parent[51];
int num[51]; //각 노드의 리프 개수

int init(int s)
{
	//리프면
	if (child[s].size() == 0)
	{
		return num[s] = 1;
	}

	for (int i = 0; i < child[s].size(); i++)
	{
		num[s] += init(child[s][i]);
	}
	return num[s];
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	int t, root;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		parent[i] = t;
		if (t == -1)
		{
			root = i;
			continue;
		}
		child[t].push_back(i); // t의 자식 i
	}

	init(root); //각 노드의 리프 개수 저장됨.
	int R;
	cin >> R;
	//R의 부모가 리프가 되는 경우를 고려해야함!!!
	if (root == R) cout << 0;
	else if (child[parent[R]].size() == 1) cout << num[root] - num[R] + 1;
	else cout << num[root] - num[R];
}