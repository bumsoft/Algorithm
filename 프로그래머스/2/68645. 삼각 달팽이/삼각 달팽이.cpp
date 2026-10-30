#include <bits/stdc++.h>

using namespace std;

// 시뮬로 할거냐, 다른 방법으로 할거냐.
//1
//2 9
//3 10 8 
//4 5 6 7

// 0 1 3 6 : i*

int board[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    
    int r = 0;
    int c = 0;
    int cnt = 1;
    int dir = 0; // 0: 아래 1: 오른 2: 위(대각)
    
    int e = 0;
    for(int i=1;i<=n;i++)
    {
        e += i;
    }
    while(1)
    {
        if(cnt > e) break;
        if(dir==0)
        {
            board[r][c] = cnt++;
            r++;
            if(r==n || board[r][c]!=0)
            {
                r--;
                c++;
                dir = 1;
            }
        }
        else if(dir == 1)
        {
            board[r][c] = cnt++;
            c++;
            if(c==n || board[r][c]!=0)
            {
                c-=2;
                r--;
                dir = 2;
            }
        }
        else
        {
            board[r][c] = cnt++;
            r--;
            c--;
            if(board[r][c]!=0 || board[r][c]!=0)
            {
                dir = 0;
                r+=2;
                c++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}