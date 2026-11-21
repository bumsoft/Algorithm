#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
queue<int> Q;
bool vis[5'002];
vector<int> V[5'002];

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> N >> M >> K;
   int u, v;
   for (int i = 0; i < M; i++)
   {
      cin >> u >> v;
      V[u].push_back(v);
      V[v].push_back(u);
   }
   int k;
   for (int i = 0; i < K; i++)
   {
      cin >> k;
      vis[k] = true;
   }
   vis[1] = true;
   Q.push(1);

   int ans = -1;
   while (!Q.empty())
   {
      int ver = Q.front();
      ans++;
      Q.pop();
      for (int i = 0; i < V[ver].size(); i++)
      {
         if (vis[V[ver][i]]) continue;
         Q.push(V[ver][i]);
         vis[V[ver][i]] = true;
      }
   }
   cout << ans;


}