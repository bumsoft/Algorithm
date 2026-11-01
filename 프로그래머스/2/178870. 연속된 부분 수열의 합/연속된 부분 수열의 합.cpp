#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int len=INT_MAX; // 지금까지 찾은 것 중 가장 짧은 길이
    int a_s=-1;
    int a_e=-1;
    int s=0;
    int e=0;
    
    int sum = sequence[0];
    while(1)
    {
        if(sum < k)
        {
            //e범위 체크
            if(e == sequence.size()-1) break;
            e++;
            sum+=sequence[e];
            continue;
        }
        if(sum == k)
        {
            if(e - s + 1 < len) //갱신
            {
                a_s = s;
                a_e = e;
                len = e-s+1;
            }
            //e체크
            if(e == sequence.size()-1) break;
            e++;
            sum+=sequence[e];
            continue;
        }
        if(sum > k)
        {
            if(s==e)
            {
                if(e == sequence.size()-1) break;
                e++;
                sum+=sequence[e];
                continue;
            }
            sum -= sequence[s];
            s++;
        }
    }
    answer.push_back(a_s);
    answer.push_back(a_e);
    return answer;
}