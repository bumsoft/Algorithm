#include <bits/stdc++.h>

// 1 100 1 100 1 100

using namespace std;

// int dp[1'000'001][2]; 
// // dp[i][0] : i번째 집 안털었을 때 최대 값
// // dp[i][1] : i번째 집 털었을 때 최대 값

// // dp[i][0] = D[i] + max(dp[i-1][0], dp[i-1][1]); //이전 집 털든 안털든 상관 X
// // dp[i][1] = D[i] + dp[i-1][0]; //이전 집 안털었어야함
// // 마지막 집이 중요한데, 마지막 집을 턴다면, 첫번째 집을 털지 않았어야하고
// //                     안턴다면, 첫번째 집은 상관 없음
// // => 상태에 첫번째 집을 넣냐 ?


int dp1[1'000'001][2]; // 1번 집을 선택한 DP

int dp0[1'000'001][2]; // 1번 집을 선택하지 않은 DP


int solution(vector<int> money) {
    int answer = 0;
    dp1[0][1] = money[0];
    dp1[0][0] = -INT_MAX;
    
    dp0[0][0] = 0;
    dp0[0][1] = -INT_MAX;
    for(int i=1;i<money.size();i++)
    {
        dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
        dp1[i][1] = money[i] + dp1[i-1][0];
        
        dp0[i][0] = max(dp0[i-1][0], dp0[i-1][1]);
        dp0[i][1] = money[i] + dp0[i-1][0];
    }
    answer = max(dp1[money.size()-1][0], max(dp0[money.size()-1][1],dp0[money.size()-1][0] ));
        
        
    return answer;
}