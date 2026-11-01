#include <bits/stdc++.h>

using namespace std;

int cnt[100'001];

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1;i<=number;i++)
    {
        int t = 1;
        while(t*i <= number)
        {
            cnt[i*t]++;
            t++;
        }
    }
    for(int i=1;i<=number;i++)
    {
        if(cnt[i] > limit) answer+=power;
        else answer+=cnt[i];
    }
    
    return answer;
}