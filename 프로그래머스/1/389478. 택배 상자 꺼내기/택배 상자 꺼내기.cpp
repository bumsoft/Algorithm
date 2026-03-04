#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    
    if(w == 1)
    {
        return n-num+1;
    }
    
    int floor = (num-1)/w; // num이 몇층에 있는지. 0층~
    int max_floor = (n-1)/w; // 전체 몇층인지
    cout<< floor << ' '<<max_floor<<'\n';
    
    if(floor == max_floor) return 1; //맨 위층이면.
    // 최상층과 현재층 사이의 완전한 층 개수
    answer += max_floor - floor - 1;
    
    // 짝수층이면 ->
    // 홀수층이면 <-
    int order = n%w; // 좌측에서 order 번째에 위치함
    if(max_floor%2!=0) //홀수층
    {
        if(order != 0)
            order = w-order + 1;
    }
    else if(order == 0) order = w;
    
    // num이 좌측에서 몇번째인지
    int num_order = num%w;
    if(floor%2!=0) //홀수층
    {
        if(num_order != 0)
            num_order = w-num_order + 1;
    }
    else
    {
        if(num_order == 0)
        {
            num_order = w;
        }
    }
    if(num_order == order) return answer+1;
    cout<<"DD"<<num_order<<' '<<order<<'\n';
    
    //둘 다 왼쪽방향에서 오는경우
    if(floor%2==0 && max_floor%2==0)
    {
        if(num_order > order) return answer;
        return answer+1;
    }
    //둘 다 오른방향에서 오는 경우
    if(floor%2==1 && max_floor%2==1)
    {
        if(num_order < order) return answer;
        return answer + 1;
    }
    //num 왼
    if(floor%2==0)
    {
        if(num_order < order) return answer;
        return answer+1;
    }
    //num 오
    else
    {
        if(num_order > order) return answer;
        return answer+1;
    }
    
    
    return answer;
}