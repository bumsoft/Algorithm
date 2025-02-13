#include <bits/stdc++.h>
using namespace std;

// 사람 100명
// 이모티콘 7개

// 이모티콘 1개에 대해서 5가지 경우의 수 존재 => 4가지?
// 모든 경우 -> 78'125가지
// 5^7 * 100 = 7'812'500
// 브루트포스

vector<vector<int>> users;
vector<int> emoticons;
int sales[8];
int N;
int E;

int buy;
int cost;
void backTracking(int n)
{
    //종료조건
    if(n == E)
    {
        int t_buy = 0;
        int t_cost = 0;
        
        for(int i=0;i<N;i++)
        {
            int total = 0;
            int p = users[i][0];
            int maxi = users[i][1];
            
            for(int j=0;j<E;j++)
            {
                if(p <= sales[j])
                {
                    total += emoticons[j] * (100-sales[j]) / 100;
                }
            }
            if(total >= maxi)
            {
                t_buy++;
            }
            else t_cost += total;
        }
        if(buy < t_buy)
        {
            buy = t_buy;
            cost = t_cost;
        }
        else if(buy == t_buy)
        {
            cost = max(cost, t_cost);
        }
        return;
    }
    
    //
    sales[n] = 10;
    backTracking(n+1);
    
    sales[n] = 20;
    backTracking(n+1);
    
    sales[n] = 30;
    backTracking(n+1);
    
    sales[n] = 40;
    backTracking(n+1);
}

vector<int> solution(vector<vector<int>> user, vector<int> emoticon) {
    vector<int> answer; //이모티콘 플러스 서비스 가입 수와 이모티콘 매출액
    N = user.size();
    E = emoticon.size();
    users = user;
    emoticons = emoticon;

    backTracking(0);
    
    answer.push_back(buy);
    answer.push_back(cost);
    return answer;
}