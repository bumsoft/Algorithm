#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> PQ; //우선순위 저장
    queue<pair<int,int>> Q; //우선순위, 초기위치 저장
    
    for(int i=0;i<priorities.size();i++)
    {
        PQ.push(priorities[i]);
        Q.push({priorities[i], i});
    }
    while(true)
    {
        auto p = Q.front();
        Q.pop();
        if(p.first < PQ.top()) //우선순위가 높은게 있다면.
        {
            Q.push(p);
            continue;
        }
        if(p.second == location)
        {
            return answer+1;
        }
        PQ.pop();
        answer++;
    }

    
    return answer;
}