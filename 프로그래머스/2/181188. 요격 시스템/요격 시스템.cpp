#include <bits/stdc++.h>

using namespace std;


int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    for(int i=0;i<targets.size();i++)
    {
        PQ.push({targets[i][0], targets[i][1]});
    }
    int a = PQ.top().first;
    int b = PQ.top().second;
    PQ.pop();
    while(!PQ.empty())
    {
        int s = PQ.top().first;
        int e = PQ.top().second;
        PQ.pop();
        if(b <= s)
        {
            answer++;
            a = s;
            b = e;
            continue;
        }
        if(b > s)
        {
            b = min(b, e);
            continue;
        }
    }
    
    return answer+1;
}