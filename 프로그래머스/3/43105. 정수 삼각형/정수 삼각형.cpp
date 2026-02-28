#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//   0
//  0 1
// 0 1 2
//0 1 2 3

// dp[height][i] = max(dp[height-1][i], dp[height-1][i-1]) + D[i];

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int height = triangle.size()-1;

    for(int i=0;i<=height;i++)
    {
        if(i==0) 
        {
            dp[0][0] = triangle[0][0];
            continue;
        }
        for(int j=0;j<triangle[i].size();j++)
        {
            if(j==0)
            {
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }
            else if(j+1 == triangle[i].size())
            {
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    for(int i=0;i<height;i++)
    {
        // answer = max(answer, dp[triangle[triangle.size()-1]][i]);
        answer = max(answer, dp[height][i]);
    }
    
    return answer;
}