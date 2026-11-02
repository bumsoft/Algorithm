#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, pair<string,int>>, vector<pair<int, pair<string,int>>>, greater<pair<int, pair<string,int>>>> PQ; 
// <시작, <이름, 소요>>
stack<pair<string, int>> ST; // <이름, 남은시간>

int trans(string t)
{
    return stoi(t.substr(0,2))*60 + stoi(t.substr(3,2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    for(int i=0;i<plans.size();i++)
    {
        string name = plans[i][0];
        int start_time = trans(plans[i][1]);
        int left = stoi(plans[i][2]);
        
        PQ.push({start_time, {name, left}});
    }
    int now = 0;
    while(1)
    {
        string now_name = "";
        int now_time = 0;
        int left_time = 0;
        if(!PQ.empty())
        {
            now_name = PQ.top().second.first;
            now_time = PQ.top().first;
            left_time = PQ.top().second.second;
            PQ.pop();
            cout<<"이번 작업은 "<<now_name<<"을 "<<now_time<<"에 "<<left_time<<"만큼 해야합니다.\n";
        }
        if(now_name == "") // PQ가 비었으면, 스택을 다 비운다.
        {
            cout<<"PQ가 없어서 스택을 비웁니다\n";
            while(!ST.empty())
            {
                answer.push_back(ST.top().first);
                cout<<ST.top().first<<"를 완료\n";
                ST.pop();
            }
            break;
        }
        while(now <= now_time) // 지금작업 시작시간까지, ST의 작업들을 수행한다.
        {
            if(ST.empty()) {cout<<"하다만 작업이 없습니다\n"; break;}
            string t_name = ST.top().first;
            int t_left = ST.top().second;
            ST.pop();
            if(now + t_left <= now_time)
            {
                now += t_left;
                answer.push_back(t_name);
                continue;
            }
            else
            {
                ST.push({t_name, t_left - (now_time - now)});
                now = now_time;
                break;
            }
        }
        // PQ거 작업해야함. 다음 PQ 올때까지.
        now = now_time;
        if(PQ.empty())
        {
            answer.push_back(now_name);
            now = now + left_time;
            continue;
        }
        int next = PQ.top().first;
        if(now + left_time <= next)
        {
            answer.push_back(now_name);
            now = now + left_time;
        }
        else
        {
            ST.push({now_name, left_time - (next - now)});
            now = next;
        }
        
    }
    return answer;
}