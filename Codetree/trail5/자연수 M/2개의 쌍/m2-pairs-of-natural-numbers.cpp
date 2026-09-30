#include <bits/stdc++.h>

using namespace std;
// 1 20 50 60

int N;
int x[100000], y[100000];
vector<pair<int,int>> v;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    //가장 큰거랑 작은거끼리 묶으면 됨
    for(int i=0;i<N;i++)
    {
        v.push_back({y[i], x[i]});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    
    int fr = 0;
    int ba = N-1;

    while(fr < ba)
    {
        int num = v[fr].first;
        int cnt = v[fr].second;

        while(cnt>0)
        {
            int b_num = v[ba].first;
            ans = max(ans, b_num+num);
            if(cnt > v[ba].second) // 마지막거보다 더 앞으로 가야함
            {
                cnt -= v[ba].second;
                v[ba].second=0;
                ba--;

                if(fr == ba)
                {
                    ans = max(ans, num + num);
                    break;
                }
                continue;
            }
            else if(cnt == v[ba].second) //같아서 끝
            {
                v[ba].second=0;
                ba--;
                fr++;
                break;
            }
            else // 마지막거가 남음
            {
                v[ba].second -= cnt;
                fr++;
                break;
            }
        }
    }
    cout<<ans;

    return 0;
}
