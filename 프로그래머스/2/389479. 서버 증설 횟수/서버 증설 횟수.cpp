#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<int> server; //서버 종료 시간
    int num = 0; //서버 개수
    for(int i=0;i<players.size();i++)
    {
        while(!server.empty())
        {
            if(server.front() == i)
            {
                server.pop();
                num--;
                continue;
            }
            break;
        }
        int player = players[i];
        if(player < m) continue;
        if(player < num*m) continue;
        int add = 0;
        while(true)
        {
            if(player >= (num+add)*m && player < (num +add+1)*m)
            {
                cout<<i<<"시에 "<<add<<"만큼 추가\n";
                num += add;
                answer += add;
                for(int kk = 0;kk<add;kk++)
                {
                    server.push(i+k);
                }
                break;
            }
            else add++;
        }
        
    }
    
    return answer;
}