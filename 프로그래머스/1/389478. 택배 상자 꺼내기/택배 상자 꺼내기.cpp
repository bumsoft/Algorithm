#include <string>
#include <vector>

using namespace std;

int board[100][111];

int solution(int n, int w, int num) {
    int answer = 0;
    bool dir = true;
    int cnt = 1;
    for(int i=0; ;i++)
    {
        if(cnt > n) break;
        if(dir)
        {
            for(int j=0;j<w;j++)
            {
                board[i][j] = cnt++;
                if(cnt > n) break;
            }
            dir = !dir;
        }
        else
        {
            for(int j=w-1;j>=0;j--)
            {
                board[i][j] = cnt++;
                if(cnt > n) break;
            }
            dir = !dir;
        }
    }
    bool c = false;
    int rr,cc;
    for(int i=0; ;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(board[i][j] == num)
            {
                rr=i; cc=j;
                c = true;
                break;
            }
        }
        if(c) break;
    }
    while(true)
    {
        if(board[rr][cc] != 0)
        {
            answer++;
            rr++;
            continue;
        }
        break;
    }
    
    return answer;
}