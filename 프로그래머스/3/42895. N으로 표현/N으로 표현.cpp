#include <bits/stdc++.h>


using namespace std;
// + - / *

unordered_set<int> save[9];

int cal(int k, int N)
{
    int t = N;
    while(--k)
    {
        t *= 10;
        t+= N;
    }
    return t;
}

int solution(int N, int number) {
    int answer = 0;
    
    save[1].insert(N);
    if(number == N) return 1;
    
    for(int i=2;i<9;i++) // 2개 써서 만들기
    {
        for(int a=1; a<i;a++) // a개 쓴 것과 i-a개 쓴 것끼리 비교
        {
            for(int ta : save[a])
            {
                for(int tb : save[i-a])
                {
                    save[i].insert(ta + tb);
                    save[i].insert(ta - tb);
                    save[i].insert(ta * tb);
                    if(tb != 0) save[i].insert(ta / tb);
                }
            }
        }
        save[i].insert(cal(i,N));
        
        
            
        for(int k : save[i])
        {
            if(k == number)
            {
                return i;
            }
        }
    }
    return -1;
}