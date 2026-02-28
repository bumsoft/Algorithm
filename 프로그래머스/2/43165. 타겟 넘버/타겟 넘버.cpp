#include <bits/stdc++.h>

using namespace std;

int ans;
int T;
vector<int> nums;

void dfs(int value, int idx)
{
    if(idx == nums.size())
    {
        if(value == T)
        {
            ans++;
        }
        return;
    }
    dfs(value + nums[idx], idx+1);
    dfs(value - nums[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    nums = numbers;
    T = target;
    
    dfs(0, 0);
    
    return ans;
}