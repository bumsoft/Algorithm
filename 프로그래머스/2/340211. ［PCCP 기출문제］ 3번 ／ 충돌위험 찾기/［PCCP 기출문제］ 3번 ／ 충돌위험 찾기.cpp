#include <bits/stdc++.h>

using namespace std;

// 1. 모두의 현재위치 저장
// 2. 모두의 목표위치 저장
// 3. 반복 시작(1초단위)
    //0. fin[]=1이면 패스
    //1. 목표 위치로 한 칸 이동
    //2. 현재 위치 갱신 및 해당 위치 ++
    //3. 목표 위치 도달 시 목표 위치를 다음 위치로 변경(없다면, fin[] = true;)
    //4. 충돌 확인(선회하며, 0으로 변경하고 지나감)
    //5. 모두 fin이면 종료

int board[101][101];
bool fin[101];
pair<int,int> cur[101];
int target[101]; //포인트 번호
vector<int> t;
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    points.insert(points.begin(), t);
    int answer = 0;
    // 마지막 포인트 인덱스
    int M = routes[0].size()-1;
    
    //현재위치 저장 & 목표위치 저장
    for(int i=0;i<routes.size();i++)
    {
        cur[i] = {points[routes[i][0]][0], 
                  points[routes[i][0]][1]};
        board[cur[i].first][cur[i].second]++;
        target[i] = 1;
    }
    while(true)
    {
        //충돌확인
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(board[i][j]>1) 
                {
                    answer++;
                }
                board[i][j] = 0;
            }
        }
        //모두 fin이면 종료
        bool again = false;
        for(int i=0;i<routes.size();i++)
        {
            if(!fin[i])
            {
                again = 1;
                break;
            }
        }
        if(!again) break;
        
        for(int i=0;i<routes.size();i++)
        {
            //fin 확인
            if(fin[i]) continue;
            
            //현재위치
            int cr = cur[i].first;
            int cc = cur[i].second;

            //목표위치
            int tr = points[routes[i][target[i]]][0];
            int tc = points[routes[i][target[i]]][1];
            
            //목표 위치로 한 칸 이동
            // r 같은 경우 -> c만 움직
            if(cr == tr)
            {
                cc += (cc < tc) ? 1 : -1;
            }
            // c 같은 경우 -> r만 움직
            else if(cc == tc)
            {
                cr += (cr < tr) ? 1 : -1;
            }
            // r c가 다른 경우 -> r 움직
            else
            {
                cr += (cr < tr) ? 1 : -1;
            }
            //목표도달 확인
            if(cr == tr && cc == tc)//도달 시
            {
                //다음 목표가 있다면?
                if(target[i] < M) target[i]++;
                //없다면?
                else fin[i] = 1;
            }
            //현재위치 저장 및 보드 갱신
            cur[i] = {cr,cc};
            board[cr][cc]++;
        }
    }
    return answer;
}