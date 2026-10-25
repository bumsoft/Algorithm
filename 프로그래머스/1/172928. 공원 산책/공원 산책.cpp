#include <bits/stdc++.h>

using namespace std;

// E W S N
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<string> park;
int N,M;

pair<int,int> cal(int r, int c, char o, int num)
{
    int order;
    if(o == 'E') order = 0;
    else if(o == 'W') order = 1;
    else if(o == 'S') order = 2;
    else order = 3;
    
    int nr = r;
    int nc = c;
    while(num--)
    {
        nr += dx[order];
        nc += dy[order];
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) return {r,c};
        if(park[nr][nc]=='X') return {r,c};
    }
    return {nr,nc};
}

vector<int> solution(vector<string> park_, vector<string> routes) {
    vector<int> answer;
    park = park_;
    N = park.size();
    M = park[0].size();
    int r,c;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(park[i][j] == 'S')
            {
                r=i;
                c=j;
            }
        }
    for(string t : routes)
    {
        pair<int,int> p = cal(r,c,t[0], t[2]-'0');
        r = p.first;
        c = p.second;
    }
    answer.push_back(r); answer.push_back(c);
    return answer;
}
// OSO
// OOO
// OXO
// OOO