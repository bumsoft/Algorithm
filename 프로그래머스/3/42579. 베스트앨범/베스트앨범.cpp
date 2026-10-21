#include <bits/stdc++.h>

using namespace std;

// 알아야 하는 것
// - 장르별, 재생 수 총합
// - 각 장르별, top곡 2개(먼저나온순)
bool comp(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

map<string, int> m_total; // 장르별 총 재생 수
map<string, pair<int,int>> m_top; // <장르, <top1, top2>>

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++)
    {
        string g = genres[i];
        int p = plays[i];
        
        //총 재생 수 갱신
        int tmp = m_total[g];
        m_total[g] = tmp + p;
        
        // 상위 2곡 갱신
        // 첫 곡인 경우
        if(tmp == 0)
        {
            m_top[g] = {i,-1};
        }
        else
        {
            auto tmp_ = m_top[g];
            //두번째 곡인 경우
            if(tmp_.second == -1)
            {
                if(plays[tmp_.first] > p)
                    m_top[g] = {tmp_.first, i};
                else
                    m_top[g] = {i, tmp_.first};
            }
            else // 이미 두 곡 다 찬 경우, 비교
            {
                int a = plays[tmp_.first];
                int b = plays[tmp_.second];
                
                if(p > a)
                {
                    m_top[g] = {i, tmp_.first};
                }
                else if(p > b)
                {
                    m_top[g] = {tmp_.first, i};
                }
            }
        }  
    }
    // 집계 했으니, 상위 장르부터 넣기
    vector<pair<string, int>> t_gen;
   // for(auto& it = m_total.begin(); it != m_total.end(); it++)
   // {
   //     t_gen.push_back({it.first, it.second});
   // }
    for(auto& t : m_total)
    {
        t_gen.push_back(t);
    }
    
    sort(t_gen.begin(), t_gen.end(), comp);
    
    for(int i=0;i<t_gen.size();i++)
    {
        string gen = t_gen[i].first;
        auto ttt = m_top[gen];
        
        answer.push_back(ttt.first);
        if(ttt.second != -1) answer.push_back(ttt.second);
    }
    
    return answer;
}
