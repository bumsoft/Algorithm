#include <iostream>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;

int ans;

void back_tracking(int nr, int nc, int cnt)
{
    int dir = move_dir[nr][nc];
    int nn = num[nr][nc];
    ans = max(ans, cnt);
    if(dir==1)
    {
        //북
        if(nr==0)
        {
            return;
        }
        if(num[nr-1][nc] > nn)
        {
            back_tracking(nr-1, nc, cnt+1);
        }
        if(nr-2 >=0 && num[nr-2][nc] > nn)
        {
            back_tracking(nr-2, nc, cnt+1);
        }
    }
    else if(dir==2)
    {
        //북동
        if(nr==0 || nc==n-1)
        {
            return;
        }
        if(num[nr-1][nc+1] > nn)
        {
            back_tracking(nr-1, nc+1, cnt+1);
        }
        if(nr-2 >=0 && nc+2<n && num[nr-2][nc+2] > nn)
        {
            back_tracking(nr-2, nc+2, cnt+1);
        }
    }
    else if(dir==3)
    {
        //동
        if(nc==n-1)
        {
            return;
        }
        if(nc+1 <n && num[nr][nc+1]>nn)
        {
            back_tracking(nr, nc+1, cnt+1);
        }
        if(nc+2<n && num[nr][nc+2]>nn)
        {
            back_tracking(nr, nc+2, cnt+1);
        }
    }
    else if(dir==4)
    {
        //동남
        if(nr==n-1 || nc==n-1)
        {
            return;
        }
        if(num[nr+1][nc+1] > nn)
        {
            back_tracking(nr+1, nc+1, cnt+1);
        }
        if(nr+2<n && nc+2<n && num[nr+2][nc+2] > nn)
        {
            back_tracking(nr+2, nc+2, cnt+1);
        }
    }
    else if(dir==5)
    {
        //남
        if(nr==n-1)
        {
            return;
        }
        if(num[nr+1][nc] > nn)
        {
            back_tracking(nr+1, nc, cnt+1);
        }
        if(nr+2 <n && num[nr+2][nc] > nn)
        {
            back_tracking(nr+2, nc, cnt+1);
        }
    }
    else if(dir==6)
    {
        //남서
        if(nr==n-1 || nc==0)
        {
            return;
        }
        if(num[nr+1][nc-1] > nn)
        {
            back_tracking(nr+1, nc-1, cnt+1);
        }
        if(nr+2 < n && nc-2 >=0 && num[nr+2][nc-2] > nn)
        {
            back_tracking(nr+2, nc-2, cnt+1);
        }
    }
    else if(dir==7)
    {
        //서
        if(nc==0)
        {
            return;
        }
        if(nc-1 >=0 && num[nr][nc-1]>nn)
        {
            back_tracking(nr, nc-1, cnt+1);
        }
        if(nc-2>=0 && num[nr][nc-2]>nn)
        {
            back_tracking(nr, nc-2, cnt+1);
        }
    }
    else
    {
        //북서
        if(nr==0 || nc==0)
        {
            return;
        }
        if(num[nr-1][nc-1] > nn)
        {
            back_tracking(nr-1, nc-1, cnt+1);
        }
        if(nr-2>=0 && nc-2>=0 && num[nr-2][nc-2]>nn)
        {
            back_tracking(nr-2,nc-2,cnt+1);
        }
    }
    
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    back_tracking(r-1,c-1,0);
    cout<<ans;

    return 0;
}
