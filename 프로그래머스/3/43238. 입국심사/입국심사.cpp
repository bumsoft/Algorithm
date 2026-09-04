#include <bits/stdc++.h>


using ll = long long;

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX;
    
    // 총 시간이 mid 일 때, 각자 처리할 수 있는 인원 수의 합 >= 사람 수(n)
    
    ll low = 0;
    ll high = 1'000'000'000L * 1'000'000'000L;
    ll mid;
    int nn = times.size();
    while(low <= high)
    {
        mid = (low + high) / 2;
        ll cnt = 0;
        for(int i=0;i<nn;i++)
        {
            cnt += mid/times[i];
        }
        if(cnt >= n)
        {
            high = mid-1;
            answer = min(answer, mid);
        }
        else
        {
            low = mid+1;
        }
    }
    
    
    return answer;
}