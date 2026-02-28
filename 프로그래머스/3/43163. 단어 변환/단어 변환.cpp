#include <bits/stdc++.h>

using namespace std;

vector<int> graph[51];
bool vis[51];
bool verify(string a, string b)
{
    if(a.size() != b.size()) return 0;
    int diff_cnt = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] != b[i]) diff_cnt++;
    }
    if(diff_cnt==1) return 1;
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    // {word + begin}내에서 그래프를 이어줌
    words.push_back(begin);
    
    for(int i=0;i<words.size();i++)
    {
        for(int j=i+1; j<words.size();j++)
        {
            if(verify(words[i], words[j]))
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    // words.size() -1를 시작정점으로 탐색 시작
    queue<pair<int,int>> Q;
    Q.push({0, words.size()-1});
    vis[words.size()-1] = 1;
    while(!Q.empty())
    {
        int now = Q.front().second;
        int dis = Q.front().first;
        if(words[now] == target) return dis;
        Q.pop();
        for(int i=0;i<graph[now].size();i++)
        {
            if(vis[graph[now][i]]) continue;
            vis[graph[now][i]] = 1;
            Q.push({dis+1, graph[now][i]});
        }
    }
    
    return 0;
}