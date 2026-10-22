#include <string>
#include <vector>

using namespace std;

// i위치에서... 왼쪽아래: i | 오른아래: i+1

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    
    
    for(int i=triangle.size()-1;i>=0;i--)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            
            if(i == triangle.size())
            {
                dp[i][j] = triangle[i][j];
                continue;
            }
            
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
    }
    
    return dp[0][0];
}