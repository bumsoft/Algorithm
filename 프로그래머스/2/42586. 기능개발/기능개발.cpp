#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> p, vector<int> speeds) {
    vector<int> answer;
    
    int day = 0;
    int cnt = 0;
    
    
    for(int i=0;i<p.size();i++)
    {
        int left = 100 - p[i]; // 현재 작업의 남은 량
        int real_left = left - day*speeds[i]; 
        
        if(real_left <= 0) //이전거랑 같이 배포 가능한 경우
        {
            cnt++;
            continue;
        }
        else //real_left가 없어질때까지 일수 넘기기
        {
            if(cnt != 0) answer.push_back(cnt);
            cnt = 0;
            
            if(real_left % speeds[i] == 0) day += real_left / speeds[i];
            else day += real_left / speeds[i] + 1;
            cnt++;
        }
    }
    if(cnt != 0) answer.push_back(cnt);
    
    return answer;
}