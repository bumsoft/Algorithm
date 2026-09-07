#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> st;
    
    for(int i=arr.size()-1; i>=0;i--)
    {
        int t = arr[i];
        if(st.empty())
        {
           st.push(t);
        }
        else
        {
            if(st.top() == arr[i]) continue;
            st.push(arr[i]);
        }
    }
    while(!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
}