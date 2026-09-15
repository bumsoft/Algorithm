#include <string>
#include <vector>
#include <queue>

using namespace std;

bool vis[201];
queue<int> Q;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        Q.push(i);
        vis[i] = 1;
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int j=0;j<n;j++)
            {
                if(j == now) continue;
                if(computers[now][j] && !vis[j])
                {
                    Q.push(j);
                    vis[j] = 1;
                }
            }
        }
        answer++;
    }


    
    return answer;
}