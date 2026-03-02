#include <bits/stdc++.h>

using namespace std;

// 정답 벡터가 <int>니 int로 가정하고 풀어보자.
// 최소PQ, 최대PQ
// map<int, int> m; 로 각 숫자의 잔여 개수 카운트

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> highPQ;
    priority_queue<int> lowPQ;
    map<int,int> m;
    int total = 0;
    for(int i=0;i<operations.size();i++)
    {
        if(operations[i][0] == 'I') // 삽입
        {
            int num = stoi(operations[i].substr(2, operations[i].size()-2));
            highPQ.push(num);
            lowPQ.push(-num);
            m[num]++;
            total++;
        }
        else if(operations[i][2] == '1') // 최댓값 삭제
        {
            if(total == 0) // 비어있다면
            {
                continue;
            }
            while(1)
            {
                int num = highPQ.top();
                highPQ.pop();
                
                if(m[num] == 0) // 이미 없다면.
                {
                    continue;
                }
                else
                {
                    m[num]--;
                    total--;
                    break;
                }
            }
        }
        else // 최솟값 삭제
        {
            if(total == 0)
            {
                continue;
            }
            while(1)
            {
                int num = -lowPQ.top();
                lowPQ.pop();
                if(m[num] == 0) continue;
                else
                {
                    m[num]--;
                    total--;
                    break;
                }
            }
        }
    }
    if(total == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else
    {
        // 최대값
        bool high = 0;
        while(1)
        {
            if(highPQ.empty()) break;
            int num = highPQ.top();
            highPQ.pop();
            if(m[num] != 0)
            {
                high = 1;
                answer.push_back(num);
                break;
            }
        }
        
        // 최소값
        while(1)
        {
            if(lowPQ.empty()) break;
            int num = -lowPQ.top();
            lowPQ.pop();
            if(m[num] != 0)
            {
                if(!high)
                {
                    answer.push_back(num);
                    answer.push_back(num);
                    break;
                }
                else
                {
                    answer.push_back(num);
                    break;
                }
            }
        }
    }
    
    
    return answer;
}