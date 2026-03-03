// 12
#include <bits/stdc++.h>
using namespace std;

// 노드가 최대 101개인 트리
// 노드마다 자식개수, 몇번째 길인지를 저장

// 백트래킹으로는 어렵다.
// 리프노드는 받는 순서가 항상 정해져있다?

vector<int> nodes[101]; // nodes[i] : i노드에서 갈 수 있는 노드 번호 리스트
int num[101]; // num[i] : node[i]의 몇번째 길 차례인지

int cnt[101];

vector<int> o;

int find_target()
{
    int now = 1;
    while(1)
    {
        if(nodes[now].size()==0) return now;
        int div = nodes[now].size();
        int order = num[now] % div;
        num[now]++;
        now = nodes[now][order];
    }
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    
    // 트리 저장
    for(int i=0;i<edges.size();i++)
    {
        nodes[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i=1;i<=target.size();i++)
    {
        sort(nodes[i].begin(), nodes[i].end());
    }
    while(1) // 하나 떨어뜨리고, 개수 cnt 후, target 계산하기
    {
        // 떨어뜨렸을 때 가는 리프 번호
        int t = find_target();
        o.push_back(t);
        cnt[t]++;
        if(cnt[t] > target[t-1]) return {-1};
        
        // 모든 노드의 현재 횟수가 target 범위에 있는지 확인
        bool p = 1;
        for(int i=0;i<target.size();i++)
        {
            if(!(cnt[i+1] <= target[i] && cnt[i+1]*3 >= target[i]))
            {
                p=0;
                break;
            }
        }
        if(!p) continue;
        
        // 가능한 경우
        for(int i=0;i<o.size();i++)
        {
            int cur = o[i];
            if(cnt[cur]==0) continue;
            // 1
            if(cnt[cur]-1 <= target[cur-1]-1 && (cnt[cur]-1)*3 >= target[cur-1]-1)
            {
                cnt[cur]--;
                target[cur-1]-=1;
                answer.push_back(1);
            }
            // 2
            else if(cnt[cur]-1 <= target[cur-1]-2 && (cnt[cur]-1)*3 >= target[cur-1]-2)
            {
                cnt[cur]--;
                target[cur-1]-=2;
                answer.push_back(2);
            }
            // 3
            else
            {
                cnt[cur]--;
                target[cur-1]-=3;
                answer.push_back(3);
            }
        }
        break;
    }
    
    return answer;
}