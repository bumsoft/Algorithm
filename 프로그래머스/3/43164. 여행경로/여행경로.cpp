#include <bits/stdc++.h>

using namespace std;

int num = 1; // 공항은 1번부터 num-1번까지임
map<string,int> m;
map<int,string> rm;
vector<int> graph[10'001];
string answer[10'001];

int ticket_nums[10'001][10'001];

int total_ticket;
bool fin;
void dfs(int idx, int now)
{
    if(fin) return;
    answer[idx] = rm[now];
    if(idx == total_ticket)
    {
        fin=1;
        return; //찾음
    }
    for(int i=0;i<graph[now].size();i++)
    {
        int next = graph[now][i];
        //now->next티켓이 없다면, 패스
        if(ticket_nums[now][next]==0) continue;
        
        //있다면 사용해서 dfs
        ticket_nums[now][next]--;
        dfs(idx+1, next);
        
        //dfs 끝나고 다시 티켓 복구
        ticket_nums[now][next]++;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    total_ticket = tickets.size();
    for(int i=0;i<tickets.size();i++)
    {
        //a->b
        string a = tickets[i][0];
        string b = tickets[i][1];
        if(m[a] == 0)
        {
            m[a] = num++;
            rm[num-1] = a;
        }
        if(m[b] == 0)
        {
            m[b] = num++;
            rm[num-1] = b;
        }
        ticket_nums[m[a]][m[b]]++;
        graph[m[a]].push_back(m[b]);
    }
    for(int i=1;i<=num-1;i++)
    {
        vector<string> temp;
        for(int j=0;j<graph[i].size();j++)
        {
            temp.push_back(rm[graph[i][j]]);
        }
        sort(temp.begin(),temp.end());
        graph[i].clear();
        for(int j=0;j<temp.size();j++)
        {
            graph[i].push_back(m[temp[j]]);
        }
        if(rm[i]=="ATL")
        {
            for(int t=0;t<graph[i].size();t++)
            {
                cout<<rm[graph[i][t]]<<' ';
            }
        }
    }
    //dfs
    dfs(0, m["ICN"]);
    vector<string> answer2;
    for(int i=0;i<=total_ticket;i++)
    {
        answer2.push_back(answer[i]);
    }
    return answer2;
}