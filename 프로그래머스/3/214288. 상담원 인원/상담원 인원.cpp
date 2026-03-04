#include <bits/stdc++.h>

using namespace std;
int K;
int ans = -1;
int wait[6][21]; //wait[i][j] : i유형에 j명멘토일때 대기시간

vector<pair<int,int>> groups[6]; // groups[i] : i유형의 요청 리스트(요청순), <요청시각, 상담시간>

int cnt[6]; // 백트래킹용, cnt[i]: i유형 멘토 수

void back_tracking(int left_mentor_num, int start) //남은 멘토 수
{
    if(left_mentor_num == 0)
    {
        int sum = 0;
        for(int i=1;i<=K;i++)
        {
            sum+=wait[i][cnt[i]];
        }
        if(ans == -1) ans = sum;
        else ans = min(ans, sum);
        return;
    }
    
    for(int i=start;i<=K;i++)
    {
        cnt[i]++;
        back_tracking(left_mentor_num - 1,i);
        cnt[i]--;
    }
}


// 멘토가 mentor_num명일 때 대기시간을 반환한다.
int sol(int group_num, int mentor_num)
{
    int res = 0;
    
    priority_queue<int> pq; //상담이 끝나는 시간이 빠른순으로 뽑는 멘토 PQ
    for(int i=0;i<mentor_num;i++)
        pq.push(0);
    
    for(int i=0;i<groups[group_num].size();i++)
    {
        int can_start_at = -pq.top(); //상담시작가능시간
        pq.pop();
        int real_start_at = groups[group_num][i].first; //희망시간
        // cout<<real_start_at<<'\n';
        int t = groups[group_num][i].second; //소요시간
        
        if(can_start_at <= real_start_at)
        {
            pq.push(-(real_start_at + t));
        }
        else
        {
            res += can_start_at - real_start_at;
            pq.push(-(can_start_at + t));
        }
    }
    return res;
}

int solution(int k, int n, vector<vector<int>> reqs) {

    K = k;
    // 1. 모든 그룹에 대해 1~n명일 때의 대기시간을 구한다.
    for(int i=0;i<reqs.size();i++)
    {
        int c = reqs[i][2]; //상담유형
        int a = reqs[i][0]; //요청시각
        int b = reqs[i][1]; //상담길이
        // cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";
        groups[c].push_back({a,b});
    }
    // 각 그룹 별, 멘토 수에 따른 대기 시간 구함
    for(int i=1;i<=k;i++) // 그룹별
    {
        for(int j=1;j<=n;j++) // 멘토수별
        {
            int wait_time = sol(i,j);
            wait[i][j] = wait_time;
            // cout<<i<<"유형 "<<j<<"명"<<wait_time<<'\n';
        }
    }
    
    // 2. 모든 멘토 배정 경우의 수를 보고, 최소값을 구한다.
    for(int i=1;i<=k;i++)
        cnt[i]=1;
    back_tracking(n-k, 1);
    
    return ans;
}