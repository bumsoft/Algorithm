#include <bits/stdc++.h>

using namespace std;
using ll = long long;


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // 1행 1열 ~ i행 i열까지 모두 i로 채움

    
    // 1 2 3 4
    // 2 2 3 4
    // 3 3 3 4
    // 4 4 4 4
    
    // 1행부터 시작한다고 할 때.
    // idx = 10 일 때, 11로 만들고, 해당 인덱스는 11/n +1 행에 위치함
    // 해당 인덱스는 11%n 열에 위치함
    // 열 > 행 => 열
    // 열 <= 행 => 행
    for(ll i = left;i<=right;i++)
    {
        ll row = i / n + 1;
        ll col = i%n + 1;
        // cout<<"i: "<<i<<'\n';
        // cout<<"row: "<<row<<" col: " << col <<'\n';
        if(col > row) answer.push_back(col);
        else answer.push_back(row);
    }

    
    return answer;
}