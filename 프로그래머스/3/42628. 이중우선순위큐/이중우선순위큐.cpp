#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> o) {
    vector<int> answer;
    
    multiset<int> ms;
    
    for(int i=0;i<o.size();i++)
    {
        if(o[i][0] == 'I')
        {
            int num = stoi(o[i].substr(2, o[i].size()-2));
            ms.insert(num);
        }
        else if(o[i][2] == '1')
        {
            if(ms.size()==0) continue;
            ms.erase(prev(ms.end()));
        }
        else
        {
            if(ms.size()==0) continue;
            ms.erase(ms.begin());
        }
    }
    if(ms.size()==0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(prev(ms.end())));
        answer.push_back(*(ms.begin()));
    }
    
    return answer;
}