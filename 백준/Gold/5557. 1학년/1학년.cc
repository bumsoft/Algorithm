#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

ll arr[101];

ll dp[101][21]; //[i][j]: i번까지 연산 값이 j인 경우의 수

//도중에 결과가 음수거나 20초과면 안됨.
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    ll result = arr[N];

    dp[1][arr[1]] = 1;

    for (ll i = 2; i < N; i++)
    {
        for (ll j = 0; j < 21; j++)
        {
            //i번째 더해서 j가 됨
            if (j-arr[i] >= 0)
            {
                dp[i][j] += dp[i - 1][j - arr[i]];
            }

            //i번째 빼서 j가 됨
            if (j + arr[i] <= 20)
            {
                dp[i][j] += dp[i - 1][j + arr[i]];
            }
        }
    }
    cout << dp[N-1][result];
    return 0;
}