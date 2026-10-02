#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100000];
int ans = INT_MAX;
int cnt[100'001]; // cnt[i]: 현재 구간에서 i의 개수

bool tmp[100'001];

void init_tmp()
{
    for(int i=1;i<=m;i++)
    {
        tmp[i]=0;
    }
}

// 구간 s~e 밖의 구간에 1~M이 존재하는지 확인하는 함수(s,e를 포함하지 않는다)
bool outs(int s, int e)
{
    init_tmp();
    for(int i=0;i<s;i++)
    {
        tmp[arr[i]]=1;
    }
    for(int i=e+1;i<n;i++)
    {
        tmp[arr[i]]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(tmp[i]==0) return 0;
    }
    return 1;
}

bool in() //현재 구간에 존재하는지 확인
{

    for(int i=1;i<=m;i++)
    {
        if(cnt[i]==0) return 0;
    }
    return 1;
}

vector<pair<int,int>> cann;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 구간의 길이는 최소 M
    // 0~M 구간부터 0~ M++..로 끝을 늘리면서 처음 나오는 구간을 찾는다.
    // 찾았다면, 앞구간을 줄이면서 만족하는지 확인해본다.(구간 길이가 M일때까지)
    // 앞을 더 줄일 수 없다면 다시 뒤를 늘리면서 나오는 구간을 찾는다.
    // 찾으면 다시 앞을 줄인다.

    // 위 과정 중, 찾았다면, 일단 지금까지 구간보다 작은 지 확인하고, 작다면 구간 밖도 검사한다.
    
    // 0~M구간을 센다.
    for(int i=0;i<m;i++)
    {
        cnt[arr[i]]++;
    }
    bool sat = true;
    for(int i=1;i<=m;i++)
    {
        if(cnt[i] == 0)
        {
            sat = false;
            break;
        }
    }
    ///
    int s = 0;
    int e = m-1;
    while(true)
    {
        //cout<<sat<<'\n';
        //cout<<"s: "<<s<<" e: "<<e<<'\n';
        if(e > n-1) break;
        if(sat && e - s + 1 >= m) // 만족한다면, 앞을 줄인다.
        {
            int rm = arr[s++];
            cnt[rm]--;
            if(cnt[rm]==0) // 앞 줄였는데 만족 안하면....
            {
                sat = false;
            }
            else // 앞 줄였는데 만족 하면...
            {
                cann.push_back({s,e});
            }
        }
        else
        {
            e++;
            cnt[arr[e]]++;
            if(cnt[arr[e]]>1) continue;
            else // 새로 추가된 경우
            {
                bool ck = in();
                if(ck)
                {
                    cann.push_back({s,e});
                    sat = 1;
                }
            }
        }
    }

    for(int i=0;i<cann.size();i++)
    {
        if(cann[i].second - cann[i].first + 1 < ans)
        {
            bool ck = outs(cann[i].first, cann[i].second);
            if(ck) ans = min(ans,cann[i].second - cann[i].first + 1 );
        }
    }

    if(ans == INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}