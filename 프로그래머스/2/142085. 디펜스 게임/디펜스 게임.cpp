#include <bits/stdc++.h>

using namespace std;

// 적의 총합이 n 이하인 최대 라운드에서, 지금까지의 라운드 중 가장 큰 것 순으로 제거하면서 추가로 진행


int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    int sum=0;
    int r = 0;
    priority_queue<int> PQ;
    for(int i=0;i<enemy.size();i++)
    {
        sum+= enemy[i];
        if(sum > n)
        {
            sum-=enemy[i];
            break;
        }
        r=i;
        PQ.push(enemy[i]);
    }
    int left = n - sum;
    if(sum==0) r--;
    for(int i=r+1;i<enemy.size();i++)
    {
        int e = enemy[i];
        PQ.push(e);
        
        while(!PQ.empty())
        {
            if(k==0 || left >= e)
            {
                break;
            }
            k--;
            left += PQ.top();
            PQ.pop();
        }
        if(left < e)
        {
            break;
        }
        left -= e;
        r++;
    }
    if(r==-1) return 0;
    return r+1;
}