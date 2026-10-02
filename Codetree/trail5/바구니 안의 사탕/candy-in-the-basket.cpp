#include <iostream>

using namespace std;

int N, K;

int num[1'000'002];

int main() {
    cin >> N >> K;

    int a,b;
    for (int i = 0; i < N; i++) {
        cin >> a>>b;
        num[b] += a;
    }

    // c-k ~ c+k
    // 0 ~ 2k
    int start = 0;
    int end_ = 2*K;
    int ans = 0;
    for(int i=0;i<min(end_, 1'000'001);i++)
    {
        ans+=num[i];
    }
    int cur = ans;
    for(int i=2*K + 1;i<=1'000'001;i++)
    {
        cur += num[i];
        cur -= num[start++];
        ans = max(ans, cur);
    }
    cout<<ans;

    return 0;
}
