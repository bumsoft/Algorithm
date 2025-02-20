#include <bits/stdc++.h>
using namespace std;



int dp[41][150];



int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    for(int i=0;i<41;i++)
    {
        for(int j=0;j<150;j++)
        {
            dp[i][j] = 200;
        }
    }
    
    //A가 훔친경우
    dp[0][0] = info[0][0];
    
    //B가 훔친경우
    dp[0][info[0][1]] = 0;
    
    for(int i=1;i<info.size();i++)
    {
        for(int j=0;j<=120;j++)
        {
            //B가 훔치는게 불가능한 경우
            if( j - info[i][1] < 0) dp[i][j] = dp[i-1][j] + info[i][0];
            
            //i번째 물건에서, B의 흔적 j이려면?
            // B가 훔친경우
            else dp[i][j] = min(dp[i-1][j-info[i][1]], dp[i-1][j] + info[i][0]);
        }
    }
    
    int ans = INT_MAX;
    for(int i=0;i<m;i++)
    {
         ans = min(ans, dp[info.size()-1][i]);
    }
    if(ans >= n) answer = -1;
    else answer = ans;
    return answer;
}