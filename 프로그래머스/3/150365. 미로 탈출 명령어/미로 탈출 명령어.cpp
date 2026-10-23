#include <string>
#include <vector>

using namespace std;

// d l r u
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

//그리디

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    bool ck=0;
    while(true)
    {
        if(k==0) break;
        for(int i=0;i<4;i++)
        {
            char type;
            if(i==0) type = 'd';
            if(i==1) type = 'l';
            if(i==2) type = 'r';
            if(i==3) type = 'u';  
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > n || nx <= 0 || ny > m || ny <=0) continue;
            if(abs(r-nx) + abs(c-ny) <= k) //목적지까지 k안에 갈 수 있다면 ok
            {
                x = nx;
                y = ny;
                answer += type;
                k--;
                ck=1;
                break;
            }
        }
        if(!ck) return "impossible";
    }
    if(x != r || y != c) return "impossible";
    else return answer;
    
    return answer;
}