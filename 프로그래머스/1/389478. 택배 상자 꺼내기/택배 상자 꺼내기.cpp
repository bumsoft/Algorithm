#include <bits/stdc++.h>

using namespace std;

int arr[100][100];

int solution(int n, int w, int num) {
    int answer = 0;
    
    int now = 1;
    bool right = 1;
    int w_cnt = 0;
    int i=0;
    int j=0;
    while(1)
    {
        if(now > n) break;
        if(w_cnt<w)
        {
            if(right)
            {
                arr[i][j] =now;
                w_cnt++;
                j++;
            }
            else
            {
                arr[i][j] = now;
                w_cnt++;
                j--;
            }
        }
        else
        {
            right = !right;
            i++;
            w_cnt=0;
            if(right) j = 0;
            else j = w-1;
            
            continue;
        }
        
        now++;
    }
    int ii,jj;
    for(int i=0; ;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(arr[i][j]==num)
            {
                int answer = 1;
                while(true)
                {
                    if(arr[++i][j] != 0)
                        answer++;
                    else return answer;
                }
            }
                
        }
    }

    return 0;
}