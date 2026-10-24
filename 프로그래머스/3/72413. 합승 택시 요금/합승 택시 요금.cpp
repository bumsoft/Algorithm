#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vertex[201];

int D[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            D[i][j] = INT_MAX;
            if(i==j) D[i][j] = 0;
        }
    }
    for(int i=0;i<fares.size();i++)
    {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
        vertex[c].push_back({d,f});
        vertex[d].push_back({c,f});
        
        D[c][d] = min(f, D[c][d]);
        D[d][c] = min(f, D[d][c]);
    }
    
    for(int k=1;k<=n;k++) // k를 경유해서 감
    {
        for(int i=1;i<=n;i++)
        {
            if(D[i][k] == INT_MAX) continue;
            for(int j=1;j<=n;j++)
            {
                if(D[j][k]==INT_MAX) continue;
                
                if(D[i][j] > D[i][k] + D[j][k])
                {
                    D[i][j] = D[i][k] + D[j][k];
                    D[j][i] = D[i][k] + D[j][k];
                }
            }
        }
    }
    // 이제 모든 구간사이의 최소금액을 알고있음
    // 이제 i를 경유하면서의 최소금액을 구하면 됨
    for(int i=1;i<=n;i++)
    {
        if(D[i][s] == INT_MAX || D[i][a] == INT_MAX || D[i][b] == INT_MAX) continue;
        answer = min(answer, D[i][s] + D[i][a] + D[i][b]);
    }
    
    return answer;
}