#include <bits/stdc++.h>

using namespace std;

// 1 + 2 + 3 + ... + n + 2*n;

// 최대 1500개 정도의 집합이 들어있음 //N^2도 충분히 돈다.

// 모든 집합을 집합의 원소 개수 순으로 정렬시켜야함
// => vector<pair<int,string>>; //벡터 크기는 최대 1500

bool vis[100'001];
bool my_comp(const string& a, const string& b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<string> v;
    s = s.substr(1,s.size()-2);
    // "},{" 기준으로 분리한다.
    int start = 1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='}')
        {
            v.push_back(s.substr(start, i-start));
            i += 2;
            start = i+1;
        }
    }
    sort(v.begin(), v.end(), my_comp);
    for(int i=0;i<v.size();i++)
    {
        stringstream ss(v[i]);
        string x;
        while(getline(ss, x, ','))
        {
            int num = stoi(x);
            if(vis[num]) continue;
            vis[num] = 1;
            answer.push_back(num);
        }
    }
    return answer;
}