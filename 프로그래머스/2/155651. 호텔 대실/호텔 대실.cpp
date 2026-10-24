#include <bits/stdc++.h>
using namespace std;

int trans(string t)
{
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

int solution(vector<vector<string>> book_time)
{
    vector<pair<int, int>> v;

    for(auto &b : book_time)
    {
        int s = trans(b[0]);
        int e = trans(b[1]) + 10;

        v.push_back({s, e});
    }

    // 시작 시간 오름차순 정렬
    sort(v.begin(), v.end());

    // 객실이 다시 사용 가능해지는 시간 저장 (최소 힙)
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto [s, e] : v)
    {
        // 가장 빨리 비는 객실 재사용
        if(!pq.empty() && pq.top() <= s)
        {
            pq.pop();
        }

        // 새 예약 배정
        pq.push(e);
    }

    // 필요한 최소 객실 수
    return pq.size();
}