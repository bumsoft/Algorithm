#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 파라매트릭 서치
// 10만 * log시간
// mid = 시간
// 유의할 점은, 2번 보급할 때, 걸리는 시간은 time * 3 이라는 점(복귀는 고려X) 
// 즉, mid 시간동안, mid / (time*2) + (mid % (time*2))/time 번 보급이 가능하다.
// 각 도시에서 금을 먼저 가져오고, 공간이 남으면 은도 가져온다. 그리고, 금 대신 가져올 수 있던 은의 개수를 기록한다.
// 합산 결과, 금이 부족하다면 불가능
//         , 은이 부족하다면, 대신 가져올 수 있었던 은으로 가능한지 보고, 금에서 필요한 만큼 뺀다.
            // 그랬는데도 금이 충분하다면 가능한것이다.

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    ll start = 0;
    ll mid;
    ll end = 100'000LL*1'000'000'000 * 4;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
     // cout<<mid<<'\n';   
        ll gold = 0;
        ll silver = 0;
        ll exchange_silver = 0;
        for(int i=0;i<g.size();i++)
        {
            // cout<<i<<"번 도시\n";
            ll n = mid / (t[i]*2) + (mid % (t[i]*2))/t[i]; //n번 보급
            ll max_gold = min(n * w[i], (ll)g[i]);
            ll av = n*w[i] - max_gold; // 더 가져갈 수 있는 양
            ll max_silver=0;
            if(av > 0)
            {
                max_silver = min(av, (ll)s[i]);
            }
            // 골드 대신 은을 가져간다면 얼마나 가져갈 수 있는지.
            ll ex_s = min(max_gold, s[i]-max_silver);
            gold += max_gold;
            silver += max_silver;
            exchange_silver += ex_s;
            
            // cout<<"n:"<<n<<" max_gold"<<max_gold<<"max_silver"<<max_silver<<'\n';
        }
        // cout<<"가져간 금:"<<gold<<" 은: "<<silver<<'\n';
        if(gold < a)
        {
            start = mid + 1;
            continue;
        }
        // 골드가 넘친다면?
        ll diff = gold - a;
        //diff만큼 은으로 바꿔보자.
        ll ex = min(diff, exchange_silver);
        silver += ex;
        if(silver < b)
        {
            start = mid + 1;
            continue;
        }
        end = mid - 1;
        if(answer == -1) answer = mid;
        else answer = min(answer, mid);
    }
    
    
    
    return answer;
}