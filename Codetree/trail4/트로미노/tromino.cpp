#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int si1[3] = {0,0,-1};
int sj1[3] = {0,1,0};

int si2[3] = {0,0,-1};
int sj2[3] = {0,-1,0};

int si3[3] = {0,0,1};
int sj3[3] = {0,-1,0};

int si4[3] = {0,0,1};
int sj4[3] = {0,1,0};

int ti1[3] = {0,0,0};
int tj1[3] = {0,-1,1};

int ti2[3] = {0,1,-1};
int tj2[3] = {0,0,0};

int temp[6];
int ans;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    // [i][j]가 각 블럭의 중심이라고 가정하고, [i][j]에서 가능한 경우 4 + 2가지를 모두 계산해본다.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int ttt=0;ttt<6;ttt++) temp[ttt]=0;
            for(int a=0;a<3;a++)
            {
                if(i+si1[a]>=0 && i+si1[a]<n && j+sj1[a] >=0 && j+sj1[a] <m)
                {
                    if(temp[0]!=-1) temp[0] += grid[i+si1[a]][j+sj1[a]];
                }
                else
                {
                    temp[0] = -1;
                }

                if(i+si2[a]>=0 && i+si2[a]<n && j+sj2[a] >=0 && j+sj2[a] <m)
                {
                    if(temp[1]!=-1) temp[1] += grid[i+si2[a]][j+sj2[a]];
                }
                else
                {
                    temp[1] = -1;
                }

                if(i+si3[a]>=0 && i+si3[a]<n && j+sj3[a] >=0 && j+sj3[a] <m)
                {
                    if(temp[2]!=-1) temp[2] += grid[i+si3[a]][j+sj3[a]];
                }
                else
                {
                    temp[2] = -1;
                }

                if(i+si4[a]>=0 && i+si4[a]<n && j+sj4[a] >=0 && j+sj4[a] <m)
                {
                    if(temp[3]!=-1) temp[3] += grid[i+si4[a]][j+sj4[a]];
                }
                else
                {
                    temp[3] = -1;
                }

                if(i+ti1[a]>=0 && i+ti1[a]<n && j+tj1[a] >=0 && j+tj1[a] <m)
                {
                    if(temp[4]!=-1) temp[4] += grid[i+ti1[a]][j+tj1[a]];
                }
                else
                {
                    temp[4] = -1;
                }

                if(i+ti2[a]>=0 && i+ti2[a]<n && j+tj2[a] >=0 && j+tj2[a] <m)
                {
                    if(temp[5]!=-1) temp[5] += grid[i+ti2[a]][j+tj2[a]];
                }
                else
                {
                    temp[5] = -1;
                }
            }
            for(int ttt=0;ttt<6;ttt++)
            {
                ans = max(ans, temp[ttt]);
            }
        }
    }
    cout<<ans;
    return 0;
}
