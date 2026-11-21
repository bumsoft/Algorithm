#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
ll K, KK;
ll M;
ll cnt;
priority_queue<ll> PQ;
vector<int> V;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        V.push_back(temp);
    }
    ll sa = V[0];
    int loc = 0;
    for (int i = 1; i < N; i++)
    {
        if (V[i] < sa)
        {
            loc = i;
        }
        else sa = V[i];
    }
    if (loc != 0)
    {
        for (int i = 0; i <= loc; i++)
        {
            KK += sa - V[i];
            V[i] = sa;
        }
    }

    cin >> K;
    K -= KK;
    ll ans = 0;
    if (K>=0 && loc != 0)
    {
        ans += 1;
    }

    for (int i = 0; i < N; i++)
    {
        PQ.push(-V[i]);
    }
    ll save;
    ll num = 1;
    ll diff;
    while (!PQ.empty() && K > 0)
    {
        save = -PQ.top();
        PQ.pop();

        while (!PQ.empty() && K > 0)
        {
            if (-PQ.top() == save)
            {
                PQ.pop();
                num++;
            }
            else
            {
                diff = -PQ.top() - save; //차이.

                if (K - diff * num >=0)
                {
                    K -= diff * num;
                    ans += diff;
                }
                else
                {
                    ans+= K / num;
                    K = 0;
                }
                if (K >= 0)
                {
                    num++;
                }
                break;
            }
        }
    }
    if (K > 0)
    {
        ans += K / N;
    }
    cout << ans;


	return 0;
}