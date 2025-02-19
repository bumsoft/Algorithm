#include <bits/stdc++.h>
using namespace std;

//각 노드의 연결된 노드의 개수를 저장.
//각 노드에 대해서 bfs진행(트리단위로 될거임)
// 홀수 노드 - 노드의 번호가 홀수이며 자식 노드의 개수가 홀수
// 짝수 노드 - 노드의 번호가 짝수이며 자식 노드의 개수가 짝수
// 역홀수 노드 - 노드의 번호가 홀수이며 자식 노드의 개수가 짝수
// 역짝수 노드 - 노드의 번호가 짝수이며 자식 노드의 개수가 홀수

// 홀짝 트리 - 홀수 노드와 짝수 노드로만 이루어진 트리입니다.
// 역홀짝 트리 - 역홀수 노드와 역짝수 노드로만 이루어진 트리입니다.

// 각 트리에 대해서,(루트는 없다고 가정한다면?
// 홀수노드 : i가 홀수 && node[i] - 1 이 홀수
// 짝수노드 : i가 짝수 && node[i] - 1 이 짝수
// 역홀수 :  i가 홀수 && node[i] - 1 이 짝수
// 역짝수 : i가 짝수 && node[i] - 1이 홀수

// 이때 루트를 하나 선택한다면, 그 노드는 변하게됨
// 홀수 -> 역홀수
// 짝수 -> 역짝수
// 역홀수 -> 홀수
// 역짝수 -> 짝수

// 한 트리에서, 노드 한개를 역/일반으로 바꿔서 홀짝 || 역홀짝 트리로 만드는 것이 가능한가? 를 보면 됨.
// 홀수 10개 짝수 10개 역홀수 1개 인 트리라면, 역홀수 -> 홀수로 바꿔서 홀짝 트리로 만드는 것이 가능하다.

int num[1'000'001];
bool vis[1'000'001];
vector<int> V[1'000'001];
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    int oddEven = 0;
    int roddEven = 0;
    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for(int i=0;i<nodes.size();i++)
    {
        if(vis[nodes[i]]) continue;
        queue<int> Q;
        Q.push(nodes[i]);
        vis[nodes[i]] = true;
        
        //bfs시작!
        int odd= 0;
        int even = 0;
        int rodd = 0;
        int reven = 0;
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            //트리에 노드 한 개만 있는 경우
            if(V[node].size() == 0)
            {
                if(node%2==1) //번호 홀수고 자식 0으로 짝수
                {
                    rodd++; //역홀수
                }
                else // 번호 짝수고, 자식 0으로 짝수
                {
                    even++;
                }
            }
            else
            {
                if(node%2==1) //번호 홀수고
                {
                    if((V[node].size()-1)%2==0) rodd++;
                    else odd++;
                }
                else // 번호 짝수고
                {
                    if((V[node].size()-1)%2==0) even++;
                    else reven++;
                }
            }
            
            for(int l =0;l<V[node].size();l++)
            {
                if(vis[V[node][l]]) continue;
                Q.push(V[node][l]);
                vis[V[node][l]] = true;
            }
        }
        //bfs끝난뒤, 개수 확인
        if(odd+even+rodd+reven == 1) //노드 한개인 경우
        {
            if(odd+even == 1) oddEven++;
            else roddEven++;
            continue;
        }
        
        if(odd + even > rodd + reven)
        {
            if(rodd+reven == 1)
            {
                oddEven++;
            }
            continue;
        }
        else if(odd + even == rodd + reven)
        {
            if(odd+even == 1)
            {
                oddEven++;
                roddEven++;
            }
            continue;
        }
        else //odd + even < rodd + reven
        {
            if(odd+even == 1)
            {
                roddEven++;
            }
            continue;
        }
    }
    
    vector<int> answer;
    answer.push_back(oddEven);
    answer.push_back(roddEven);
    return answer;
}