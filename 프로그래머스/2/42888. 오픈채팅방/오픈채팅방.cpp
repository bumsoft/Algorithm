#include <bits/stdc++.h>

using namespace std;

vector<string> split(string t)
{
    vector<string> v;
    string tmp = "";
    for(int i=0;i<t.size();i++)
    {
        if(t[i] == ' ')
        {
            v.push_back(tmp);
            tmp = "";
        }
        else tmp += t[i];
    }
    v.push_back(tmp);
    return v;
}

vector<string> solution(vector<string> record) {
    
    map<string,string> m;
    
    // 쭉 보면서, id - 이름을 기록함
    for(int i=0;i<record.size();i++)
    {
        if(record[i][0] == 'L') continue;
        vector<string> t = split(record[i]);
        m[t[1]] = t[2];
    }
    
    vector<string> answer;
    // 다시 쭉 보면서, id에 맞는 이름을 출력하면 끝
    for(int i=0;i<record.size();i++)
    {
        vector<string> t = split(record[i]);
        if(t[0][0] == 'E')
        {
            answer.push_back( m[t[1]] + "님이 들어왔습니다.");
        }
        else if(t[0][0] == 'L')
        {
            answer.push_back( m[t[1]] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}