#include <bits/stdc++.h>
using namespace std;

long long dp[1'001][60]; //각 시간에 그 온도를 유지시키는 최소 전력

//온도는 항상 + 10 해서 고려하기.

// 원래는 -10 ~ 40
// 이걸 0 ~ 50으로 바꾸고.
// 경계를 위해 +1을 해서
// 1 ~ 51로 만들자.

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    long long answer = INT_MAX;
    
    int INF = INT_MAX;
    t1+=11;
    t2+=11;
    temperature += 11;
    
    for(int i=0;i<1001;i++)
        for(int j=0;j<=52;j++) dp[i][j]=INF;

    dp[0][temperature] = 0;
    
    bool is_up = 0;
    if(temperature < t1) is_up = 0;
    else is_up = 1;
    
    for(int i=1;i<onboard.size();i++)
    {
        // onboard[i] == 1 일때는 항상 t1~t2 사이여야함.
        for(int j=1;j<=51;j++)
        {
            if(onboard[i]) // 사람이 타고있으면.
            {
                if(j<t1 || j>t2) {dp[i][j] = INF; continue;}
                // 1도 낮춰서 맞추기 
                // 유지해서 맞추기
                // 1도 높여서 맞추기
                // (꺼서 높이거나 낮추기
                
                if(is_up) // 밖이 더운경우
                {
                    dp[i][j] = min(dp[i-1][j+1]+a, min(dp[i-1][j]+b, dp[i-1][j-1]));
                }
                else //밖이 추운경우
                {
                    dp[i][j] = min(dp[i-1][j+1], min(dp[i-1][j]+b, dp[i-1][j-1]+a));
                }
            }
            else //사람이 없으면...
            {
                if(j < temperature)
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j]+b, dp[i-1][j+1]+a));
                }
                else if(j > temperature)
                {
                    dp[i][j] = min(dp[i-1][j-1]+a, min(dp[i-1][j]+b, dp[i-1][j+1]));
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j+1], dp[i-1][j]));
                }
                
            }
            //if(dp[i][j]<INF) cout<<i<<"분 "<<j-11<<"온도 " << dp[i][j]<<'\n';
        }
    }
    // 이제 가장 마지막 1에서 t1~t2 범위 내의 최소값을 구하면된다.
    int m = 0;
    for(int i=0;i<onboard.size();i++)
    {
        if(onboard[i]) m = i;
    }
    for(int i=t1;i<=t2;i++)
    {
        answer = min(dp[m][i], answer);
    }
    
    return answer;
}