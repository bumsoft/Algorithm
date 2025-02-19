#include <bits/stdc++.h>
using namespace std;

// 1~n까지의 숫자 중 5개로 구성
// m 10번의 시도
// 모든 경우의 수 백트래킹
// 30C5 = 140'000 경우의 수
bool vis[31];
vector<vector<int>> Q;
vector<int> ANS;
int answer;
int max_N;
void backTracking(int num, int n)
{
    if(max_N - n + 1 < 5-num) return;
    if(n == max_N+2) return;
    if(num == 5)
    {
        // for(int i=1;i<=max_N;i++)
        // {
        //     if(vis[i]) cout<<i<<' ';
        // }cout<<'\n';
        //검증
        bool ck = false;
        for(int i = 0; i<Q.size();i++)
        {
            //각 입력 시작
            int correct = ANS[i];
            int cnt = 0;
            for(int j=0;j<Q[i].size();j++)
            {
                if(vis[Q[i][j]]) cnt++;
            }
            if(cnt == correct)
            {
                continue;
            }
            ck = true;
            break;
        }
        if(!ck) answer++;
        return;
    }
    
    vis[n] = true;
    backTracking(num+1, n+1);
    vis[n] = false;
    backTracking(num, n+1);
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    max_N = n;
    Q = q;
    ANS = ans;
    backTracking(0,1); //0개 선택, 1 보는중
    
    return answer;
}