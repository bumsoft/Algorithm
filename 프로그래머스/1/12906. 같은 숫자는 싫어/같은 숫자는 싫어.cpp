#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int prev = arr[0];
    answer.push_back(prev);
    
    for(int i=1;i<arr.size();i++)
    {
        if(prev == arr[i]) continue;
        
        answer.push_back(arr[i]);
        prev = arr[i];
    }
    
    return answer;
}