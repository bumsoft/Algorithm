#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int answer = 0;
    int start = 1;
    int end = 1'000'000'000;
    int mid;
    int save = -1;
    
    while(start<=end)
    {
        mid = (start + end)/2;
        // 모든 간격이 mid 이상이어야한다.
        int to_remove = 0;
        int now = 0;
        bool possible = 1;
        
        for(int i=0;i<rocks.size();i++) // 도착지도 포함됨
        {
            int dis = rocks[i] - now;
            if(dis >= mid)
            {
                now = rocks[i];
                continue;
            }
            else
            {
                if(i == rocks.size()-1)
                {
                    if(distance < mid)
                        possible = 0;
                    else
                    {
                        to_remove++;
                        continue;
                    }
                }
                to_remove++;
            }
        }
        if(!possible)
        {
            end = mid - 1;
            continue;
        }
        
        if(to_remove > n) // 더 많이 제거해야한다면.
        {
            end = mid - 1;
            continue;
        }
        // else if(to_remove < n)
        // {
        //     start = mid + 1;
        // }
        else
        {
            save = max(mid, save);
            start = mid + 1;
        }
        
    }
    return save;
}