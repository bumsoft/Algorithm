#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 사람은 1000명
// 1040
//  940
int trans(int t) //t의 10분 후의 시간을 반환해줌
{
    //100으로 나눈 나머지가 분
    //100으로 나눈 몫이 시
    int h = t/100;
    int m = t%100;
    // 950 10, 
    // 951
    if(m + 10 < 60)
    {
        return t+10;
    }
    else // m+10 >= 60
    {
        h++;
        m = (m + 10) % 60;
        return h*100 + m;
    }
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<schedules.size();i++)
    {
        bool ck = false;
        int day = startday;
        int set_time = trans(schedules[i]);
        for(int j = 0;j<timelogs[i].size();j++)
        {
            if(day > 7) day = 1;
            if(day == 6 || day == 7) {day++; continue;}
            if(timelogs[i][j] > set_time)
            {
                ck = true;
                break;
            }
            day++;
        }
        if(!ck) answer++; 
    }
    
    return answer;
}