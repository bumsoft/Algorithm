#include <bits/stdc++.h>

using namespace std;

bool vis[8];

int n_max;
int ans;
vector<vector<int>> D;
void back_tracking(int cur_life)
{
     
    for(int i=0;i<n_max;i++)
    {
        if(vis[i]) continue;
        
        // 방문 안한거면, 방문 할 수 있는지 확인한다.
        if(D[i][0] <= cur_life)
        {
            vis[i] = 1;
            back_tracking(cur_life - D[i][1]);
            vis[i] = 0;
        }
    }
    int temp = 0;
    for(int i=0;i<n_max;i++)
       {
           if(vis[i]) temp++;
       }
       ans = max(temp, ans);
}

int solution(int k, vector<vector<int>> dungeons) {
    n_max = dungeons.size();
    D = dungeons;
    back_tracking(k);
    return ans;
}


// 던전 수: 1~8
// 최소량 >= 소모량
// 최소량&소모량: 1~1000
// 잔여피로도: 1~5000

// 8개 밖에 안되어서, 모든 경우의 수를 따져보면? 8! = 40320 경우의 수 -> 브루트포스로 가능
