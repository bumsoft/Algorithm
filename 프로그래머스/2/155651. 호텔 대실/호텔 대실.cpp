#include <bits/stdc++.h>

using namespace std;

int arr[1440]; // 0 ~ 1439

int trans(string t)
{
    return stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2));
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i=0;i<book_time.size();i++)
    {
        int s = trans(book_time[i][0]);
        
        int e = min(trans(book_time[i][1]) + 9, 1439);
        for(int t=s;t<=e;t++)
            arr[t]++;
    }
    for(int i=0;i<=1439;i++)
    {
        answer = max(answer, arr[i]);
    }
    return answer;
}