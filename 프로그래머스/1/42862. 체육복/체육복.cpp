#include <string>
#include <vector>

using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i=1;i<=n;i++) arr[i] = 1;
    for(int i=0;i<lost.size();i++)
    {
        arr[lost[i]] = 0;
    }
    for(int i=0;i<reserve.size();i++)
    {
        arr[reserve[i]]++;
    }
    if(arr[1]==2)
    {
        arr[2] = 1;
    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==1) continue;
        if(arr[i]==2)
        {
            if(arr[i-1]==0) arr[i-1]=1;
            else if(arr[i+1]==0) arr[i+1]=1;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>0) answer++;
    }
    
    return answer;
}