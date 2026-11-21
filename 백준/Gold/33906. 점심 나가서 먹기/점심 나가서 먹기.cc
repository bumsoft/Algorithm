#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int Acost[100'001]; //가격
int Bcost[100'001];

int AD[100'001]; //거리
int BD[100'001];

int ABD[100'001]; //카페-식당 거리

vector<pair<int, int>> V[100'001];

priority_queue<pair<int, int>> PQ1;
priority_queue<pair<int, int>> PQ2;
priority_queue<pair<int, int>> PQ3;

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> N >> M;
   for (int i = 1; i <= N; i++)
   {
      cin >> Acost[i];
      if (Acost[i] == 0) Acost[i] = INT_MAX;

      AD[i] = INT_MAX;
      BD[i] = INT_MAX;
      ABD[i] = INT_MAX;
   }
   for (int i = 1; i <= N; i++)
   {
      cin >> Bcost[i];
      if (Bcost[i] == 0) Bcost[i] = INT_MAX;
   }
   int aa, bb, cc;
   for (int i = 0; i < M; i++)
   {
      cin >> aa >> bb >> cc;
      if (aa == bb) continue;
      V[aa].push_back({ bb,cc });
      V[bb].push_back({ aa,cc });
   }
   //식당 다익스트라
   AD[1] = 0;
   PQ1.push({ 0,1 });
   while (!PQ1.empty())
   {
      int ver = PQ1.top().second;
      int cost = -PQ1.top().first;
      PQ1.pop();
      if (AD[ver] < cost) continue;
      for (int i = 0; i < V[ver].size(); i++)
      {
         int nextVer = V[ver][i].first;
         int nextCost = V[ver][i].second;
         if (cost + nextCost < AD[nextVer])
         {
            AD[nextVer] = cost + nextCost;
            PQ1.push({ -AD[nextVer],nextVer });
         }
      }
   }
   //카페 다익스트라
   BD[1] = 0;
   PQ2.push({ 0,1 });
   while (!PQ2.empty())
   {
      int ver = PQ2.top().second;
      int cost = -PQ2.top().first;
      PQ2.pop();
      if (BD[ver] < cost) continue;
      for (int i = 0; i < V[ver].size(); i++)
      {
         int nextVer = V[ver][i].first;
         int nextCost = V[ver][i].second;
         if (cost + nextCost < BD[nextVer])
         {
            BD[nextVer] = cost + nextCost;
            PQ2.push({ -BD[nextVer],nextVer });
         }
      }
   }
   //가능한 식당중 최소값
   int amin = INT_MAX;
   int a;
   int adis;
   for (int i = 1; i <= N; i++)
   {
      if (AD[i] == INT_MAX)continue;
      if (amin > Acost[i])
      {
         amin = Acost[i];
         a = i;
         adis = AD[i];
      }
   }

   int bmin = INT_MAX;
   int b;
   int bdis;
   for (int i = 1; i <= N; i++)
   {
      if (BD[i] == INT_MAX)continue;
      if (bmin > Bcost[i])
      {
         bmin = Bcost[i];
         b = i;
         bdis = BD[i];
      }
   }
   //카페-식당 다익스트라
   ABD[a] = 0;
   PQ3.push({ 0,a });
   while (!PQ3.empty())
   {
      int ver = PQ3.top().second;
      int cost = -PQ3.top().first;
      PQ3.pop();
      if (ABD[ver] < cost) continue;
      for (int i = 0; i < V[ver].size(); i++)
      {
         int nextVer = V[ver][i].first;
         int nextCost = V[ver][i].second;
         if (cost + nextCost < ABD[nextVer])
         {
            ABD[nextVer] = cost + nextCost;
            PQ3.push({ -ABD[nextVer],nextVer });
         }
      }
   }
   cout << ABD[b] + adis + bdis;


}