#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 소요시간으로 파라매트릭 서치

long long solution(int n, vector<int> times) {
    
    ll start = 1;
    ll end = 1'000'000'000LL * 1'000'000'000;
    ll mid;
    ll ans = LLONG_MAX;
    while(start<=end)
    {
        mid = (start + end)/2;
        // mid 시간동안 총 몇명을 볼 수 있는지
        ll num = 0;
        for(int i=0;i<times.size();i++)
        {
            int t = times[i];
            num += (mid / t);
        }
        if(num >= n) // 더 많이 할 수 있으면, 시간 줄여도 됨
        {
            ans = min(ans, mid);
            end = mid - 1;
            continue;
        }
        else //num < N
        {
            start = mid + 1;
        }
    }
    return ans;
}