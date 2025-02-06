#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    //배달만 할 때 순서.
    ll ans = 0;
    queue<int> Q1;
    int left = 0;
    for(int i = deliveries.size()-1; i>=0; i--)
    {
        if(deliveries[i] == 0) continue;
        
        if(left != 0)
        {
            if(deliveries[i] < left)
            {
                left -= deliveries[i];
                continue;
            }
            if(deliveries[i] == left)
            {
                left = 0;
                continue;
            }
            deliveries[i] -= left;
            left = 0;
        }
        
        if(left == 0) //새로 배달 온 경우
        {
            while(1)
            {
                if(deliveries[i] > cap)
                {
                    Q1.push(i+1);
                    deliveries[i]-=cap;
                    continue;
                }
                if(deliveries[i] == cap)
                {
                    Q1.push(i+1);
                    break;
                }
                if(deliveries[i] < cap)
                {
                    Q1.push(i+1);
                    left = cap - deliveries[i];
                    break;
                }
            }
        }

    }
    
    queue<int> Q2;
    left = 0;
    
    for(int i = pickups.size()-1; i>=0; i--)
    {
        if(pickups[i] == 0) continue;
        
        if(left != 0)
        {
            if(pickups[i] < left)
            {
                left -= pickups[i];
                continue;
            }
            if(pickups[i] == left)
            {
                left = 0;
                continue;
            }
            pickups[i] -= left;
            left = 0;
        }
        
        if(left == 0) //새로 배달 온 경우
        {
            while(1)
            {
                if(pickups[i] > cap)
                {
                    Q2.push(i+1);
                    pickups[i]-=cap;
                    continue;
                }
                if(pickups[i] == cap)
                {
                    Q2.push(i+1);
                    break;
                }
                if(pickups[i] < cap)
                {
                    Q2.push(i+1);
                    left = cap - pickups[i];
                    break;
                }
            }
        }

    }
    while(true)
    {
        if(Q1.empty()&& Q2.empty()) break;
        if(!Q1.empty() && !Q2.empty())
        {
            ans += max(Q1.front(), Q2.front())*2;
            Q1.pop();
            Q2.pop();
            continue;
        }
        if(!Q1.empty() && Q2.empty()) //1만 있는경우
        {
            ans += Q1.front()*2;
            Q1.pop();
            continue;
        }
        if(Q1.empty() && !Q2.empty()) //2만 있는경우
        {
            ans += Q2.front()*2;
            Q2.pop();
            continue;
        }
    }
    
    
    return ans;
}