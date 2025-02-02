#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    queue<int> Q;
    Q.push(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        if(Q.back() == arr[i]) continue;
        Q.push(arr[i]);
    }
    while(!Q.empty())
    {
        answer.push_back(Q.front());
        Q.pop();
    }
    return answer;
}