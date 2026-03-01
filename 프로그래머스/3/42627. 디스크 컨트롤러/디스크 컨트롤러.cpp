#include <bits/stdc++.h>

using namespace std;

// 1. 작업소요시간 짧은순
// 2. 작업요청시각 빠른순
// 3. 작업 번호 작은순
// 비선점
// 시간증가 -> 새로운 작업 PQ 삽입 -> 다음 작업 선택
// 반환 시간(turnaround time)은 작업 요청부터 종료까지.
// 반환시간의 평균의 정수부분을 반환해라!

// 1. 모든 작업을 사전PQ(요청시각순)에 삽입
// 2. 반복문을 진행한다.(사전PQ 및 대기PQ가 빌때까지 )
// 3. 현재 진행중인 작업이 있다면, 현재 시각 + 작업시각으로 변경한다.
// 3.   시간을 확인한다.
// 4.   요청시각 <= 현재시각인 작업을, 사전PQ에서 대기PQ로 삽입 (대기PQ: <소요시간,<요청시각, 번호>> 순 정렬)
// 5.   대기PQ에서 하나 꺼내서 작업시간을 갱신하고, 다음 반복이동

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,pair<int,int>>> prePQ; //<요청시각,<작업크기,번호>>
    priority_queue<pair<int,pair<int,int>>> readyPQ;//<작업소요시간,<요청시각,번호>>
    // 1. 모든 작업을 사전PQ(요청시각순)에 삽입
    for(int i=0;i<jobs.size();i++)
    {
        prePQ.push({-jobs[i][0], {-jobs[i][1], -i}});
    }
    // 2. 반복문을 진행한다.(사전PQ 및 대기PQ가 빌때까지 )
    int remaining_time = 0;
    int now = 0;
    int requested_time = 0;
    int total_turnaround_time = 0;
    while(1)
    {
        // 3. 현재 진행중인 작업이 있다면, 현재 시각 + 작업시각으로 변경한다., 반환시간 더하기
        cout<<total_turnaround_time<<'\n';
        now += remaining_time;
        remaining_time = 0;
        
        total_turnaround_time += now - requested_time;
        requested_time = now;
        
        if(prePQ.empty() && readyPQ.empty()) break; //남은 작업이 있을 수 있음에 유의
        
        // 4. 요청시각 <= 현재시각인 작업을, 사전PQ에서 대기PQ로 삽입 (대기PQ: <소요시간,<요청시각, 번호>> 순 정렬)
        while(1)
        {
            if(prePQ.empty()) break;
            pair<int,pair<int,int>> t = prePQ.top();
            if(now >= -t.first)
            {
                readyPQ.push({t.second.first, {t.first, t.second.second}});
                prePQ.pop();
            }
            else break;
        }
        // 대기PQ에 작업이 없다면, prePQ시각까지 땡긴다.
        if(readyPQ.empty())
        {
            now = -prePQ.top().first;
            requested_time = now;
            continue;
        }
        
        // 5. 대기PQ에서 하나 꺼내서 작업시간을 갱신하고, 다음 반복이동
        if(readyPQ.empty()) continue;
        pair<int,pair<int,int>> t = readyPQ.top();
        readyPQ.pop();
        requested_time = -t.second.first;
        remaining_time = -t.first;
    }
    
    
    return total_turnaround_time/jobs.size();
}