#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool vis[1'000'001];

queue<pair<int, int>> Q; //<node, distance>

int solution(int x, int y, int n) {

    vis[x] = 1;
    Q.push({x,0});
    while(!Q.empty())
    {
        int cur = Q.front().first;
        int dis = Q.front().second;
        Q.pop();
        
        if(cur == y) return dis;
        
        int add_n = cur + n;
        int mul_2 = cur * 2;
        int mul_3 = cur * 3;
        
        if(!(add_n > y || vis[add_n]))
        {
            vis[add_n] = 1;
            Q.push({add_n, dis+1});
        }
        if(!(mul_2 > y || vis[mul_2]))
        {
            vis[mul_2] = 1;
            Q.push({mul_2, dis+1});
        }
        if(!(mul_3 > y || vis[mul_3]))
        {
            vis[mul_3] = 1;
            Q.push({mul_3, dis+1});
        }
    }
    return -1;
}