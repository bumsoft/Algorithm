#include <string>
#include <vector>

using namespace std;

long long dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++)
    {
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 && j==1)
            {
                dp[1][1] = 1;
                continue;
            }
            //물 확인
            if(dp[i][j] == -1) continue;
            // 맨 처음 예외처리
            if(j==1) 
            {
                dp[i][j] = dp[i-1][j];
                dp[i][j] %= 1'000'000'007;
                continue;
            }
            if(i==1) 
            {
                dp[i][j] = dp[i][j-1];
                dp[i][j] %= 1'000'000'007;
                continue;
            }
            dp[i][j] = ((dp[i-1][j]==-1)?0:dp[i-1][j]) + ((dp[i][j-1]==-1)?0:dp[i][j-1]);
            dp[i][j] %= 1'000'000'007;
        }
    }
    
    return dp[m][n]%1'000'000'007;
}