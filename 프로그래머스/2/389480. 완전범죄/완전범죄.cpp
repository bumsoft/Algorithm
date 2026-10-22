#include <bits/stdc++.h>

using namespace std;

// 모든 물건을 훔친다. 즉 각 물건에 대해서는 A 또는 B가 훔치는 선택지만이 존재함. => 안훔치는 경우는 없다.

int dp[120][40]; // dp[i][j]: j번 물건까지 훔쳤을 때, B의 흔적 i일때 A의 흔적 최소되도록

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<info.size();j++)
        {
            int a = info[j][0];
            int b = info[j][1];
            if(i-b<0) // a가 훔쳐야함d
            {
                dp[i][j] = dp[i][j-1]+a;
            }
            else
            {
                dp[i][j] = min(dp[i-b][j-1], dp[i][j-1] + a);
            }
            cout<<"dp["<<i<<"]["<<j<<"]: "<< dp[i][j]<<'\n';
        }
    }
    answer = n;
    for(int i=0;i<m;i++)
    {
        cout<<dp[i][info.size()-1]<<' ';
        answer = min(dp[i][info.size()-1], answer);
    }
    if(answer >= n) return -1;
    
    return answer;
}