#include <iostream>

using namespace std;

int n, m, k;
int nums[12];

int arr[4]; //arr[i]: i번 말의 이동 거리
int ans;

void back_tracking(int cnt)
{
    if(cnt == n)
    {
        int score = 0;
        for(int i=0;i<k;i++)
        {
            if(arr[i] >= m-1) score++;
            //cout<<arr[i]<<' ';
        }
        //cout<<'\n';
        ans = max(ans, score);
        return;
    }
    for(int i=0;i<k;i++)
    {
        arr[i] += nums[cnt];
        back_tracking(cnt+1);
        arr[i] -= nums[cnt];
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    back_tracking(0);
    cout<<ans;

    return 0;
}
