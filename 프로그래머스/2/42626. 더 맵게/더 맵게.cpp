#include <bits/stdc++.h>

using namespace std;

// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> PQ;
    for(int i=0;i<scoville.size();i++)
    {
        PQ.push(-scoville[i]);
    }
    int cnt = 0;
    while(!PQ.empty())
    {
        int now = -PQ.top();
        if(now >= K)
        {
            return cnt;
        }
        PQ.pop();
        if(!PQ.empty())
        {
            int next = -PQ.top();
            PQ.pop();
            PQ.push(-(now + next*2));
            cnt++;
        }
        
    }
    return -1;
    
    return answer;
}