#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int N=n;
    int M=m;
    // Please write your code here.
    int ans = 0;
    //행 수열 읽기
    for(int i=0;i<N;i++)
    {
        int m_cnt=1;
        int cnt = 1;
        int prev = grid[i][0];
        for(int j=1;j<N;j++)
        {
            if(grid[i][j] == prev)
            {
                cnt++;
            }
            else
            {
                m_cnt = max(m_cnt,cnt);
                prev = grid[i][j];
                cnt=1;
            }
        }
        m_cnt = max(m_cnt, cnt);
        if(m_cnt >= M) ans++;
    }

    //열 수열 읽기
    for(int j=0;j<N;j++)
    {
            int m_cnt=1;
            int cnt=1;
            int prev = grid[0][j];
        for(int i=1;i<N;i++)
        {
            if(grid[i][j] == prev)
            {
                cnt++;
            }
            else
            {
                m_cnt = max(m_cnt, cnt);
                prev = grid[i][j];
                cnt=1;
            }
        }
        m_cnt = max(m_cnt, cnt);
        if(m_cnt >= M) ans++;
    }
    cout<<ans;

    return 0;
}
