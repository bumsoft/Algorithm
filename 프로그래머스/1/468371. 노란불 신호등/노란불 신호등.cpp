#include <string>
#include <vector>
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}


int solution(vector<vector<int>> signals) {
    int answer = 0;
    
    ll _lcm = signals[0][0] + signals[0][1] + signals[0][2];
    
    for(int i=1;i<signals.size();i++)
    {
        _lcm = lcm(_lcm, signals[i][0] + signals[i][1] + signals[i][2]);
    }
    
    for(int i=1;i<=_lcm;i++)
    {
        bool ck = 0;
        for(int j=0;j<signals.size();j++)
        {
            int sum = signals[j][0] + signals[j][1] + signals[j][2];
            if( i%sum - signals[j][0] <= signals[j][1] && i%sum - signals[j][0] > 0) continue;
            else
            {
                ck = 1;
                break;
            }
        }
        if(ck == 0)
        {
            return i;
        }
    }
    
    return -1;
}
