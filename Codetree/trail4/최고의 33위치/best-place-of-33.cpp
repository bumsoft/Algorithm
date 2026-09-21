#include <iostream>

using namespace std;

int N;
int grid[20][20];

int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,0,1,-1,0,1};

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<N-1;j++)
        {
            int temp=0;
            for(int t=0;t<9;t++)
            {
                if(grid[i+dx[t]][j+dy[t]]) temp++;
            }
            ans = max(temp,ans);
        }
    }
    cout<<ans;

    return 0;
}
