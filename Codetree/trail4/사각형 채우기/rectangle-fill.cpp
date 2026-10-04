#include <iostream>

using namespace std;

int n;

int dp1[1'001];
int dp2[1'001];

int main() {
    cin >> n;

    // Please write your code here.
    // 맨 처음 고장한 버전으로 각각 dp
    
    // 처음에 세로 1개
    dp1[0] = 1;
    dp1[1] = 1;
    for(int i=2;i<n;i++)
    {
        dp1[i] = dp1[i-1] + dp1[i-2];
        dp1[i] %= 10'007;
    }

    //처음에 가로 2개
    dp2[0] = 0;
    dp2[1] = 1;
    for(int i=2;i<n;i++)
    {
        dp2[i] = dp2[i-1] + dp2[i-2];
        dp2[i] %= 10'007;
    }
    cout<< (dp1[n-1] + dp2[n-1])%10'007;


    return 0;
}
