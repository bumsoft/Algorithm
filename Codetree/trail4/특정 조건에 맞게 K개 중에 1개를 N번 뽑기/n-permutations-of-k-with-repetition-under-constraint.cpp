#include <iostream>

using namespace std;

int K, N;

int arr[8];
void back_tracking(int idx)
{
    if(idx == N)
    {
        bool ck = false;
        int prev = arr[0];
        int cnt = 1;
        for(int i=1;i<N;i++)
        {
            if(arr[i] == prev)
            {
                cnt++;
                if(cnt == 3) return;
            }
            else
            {
                cnt=1;
                prev = arr[i];
            }
        }
        for(int i=0;i<N;i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=1;i<=K;i++)
    {
        arr[idx] = i;
        back_tracking(idx+1);
    }
}

int main() {
    cin >> K >> N; // 1 ~ K 이하의 수 중 N개를 고르는 모든 경우(수열)(단, N개가 모두 같은 수는 제외)

    // Please write your code here.
    back_tracking(0);

    return 0;
}
