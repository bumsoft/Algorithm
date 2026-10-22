#include <string>
#include <vector>

using namespace std;

// dp[i] = max(dp[i-2] + money[i] , dp[i-1]);
// 시작점 고정해두고 두 번 하기

int dp0[1'000'001];
int dp1[1'000'001];

int solution(vector<int> money) {
    int answer = 0;
    
    dp0[0] = money[0];
    dp0[1] = money[0];
    
    for(int i=2;i<money.size();i++)
    {
        dp0[i] = max(dp0[i-2] + money[i], dp0[i-1]);
    }
    
    dp1[0] = 0;
    dp1[1] = money[1];
    for(int i=2;i<money.size();i++)
    {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    
    return max(dp0[money.size()-2], dp1[money.size()-1]);
}