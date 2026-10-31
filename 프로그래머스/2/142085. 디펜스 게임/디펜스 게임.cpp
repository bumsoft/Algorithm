#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i=0;i<enemy.size();i++)
    {
        PQ.push(enemy[i]);
        if(PQ.size() > k)
        {
            int e = PQ.top();
            PQ.pop();
            if(n < e) return i;
            n-=e;
        }
        answer++;
    }
    
    return answer;
}