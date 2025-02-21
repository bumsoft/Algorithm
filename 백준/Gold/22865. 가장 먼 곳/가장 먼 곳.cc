#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;

//A B C로부터 가장 먼 곳에 집을 구하려고함
// 거리: 가자 가까운 친구의 집까지의 거리

// 다익스트라 N번 하면 안됨
// A B C에서 각각 해봐야할듯
// A[]: o o o o o ...
// B[]: x x x x x ...
// C[]: y y y y y ...
// 이때 min(A[i],B[i],C[i])가 가장 작은 곳이 구하는 집이다!

vector<pair<int,int>> VERTEX[100'001];
int A[100'001];
int B[100'001];
int C[100'001];

void dijkstraA(int start)
{
    for (int i = 1; i <= N; i++)
    {
        A[i] = INT_MAX;
    }
    A[start] = 0;
    priority_queue<pair<int, int>> PQ;
    PQ.push({ 0, start });
    while (!PQ.empty())
    {
        int ver = PQ.top().second;
        int cost = -PQ.top().first;
        PQ.pop();
        if (cost > A[ver]) continue;
        for (int i = 0; i < VERTEX[ver].size(); i++)
        {
            int nVer = VERTEX[ver][i].first;
            int nCost = VERTEX[ver][i].second;

            if (A[nVer] > cost + nCost)
            {
                A[nVer] = cost + nCost;
                PQ.push({ -A[nVer], nVer });
            }
        }
    }
}
void dijkstraB(int start)
{
    for (int i = 1; i <= N; i++)
    {
        B[i] = INT_MAX;
    }
    B[start] = 0;
    priority_queue<pair<int, int>> PQ;
    PQ.push({ 0, start });
    while (!PQ.empty())
    {
        int ver = PQ.top().second;
        int cost = -PQ.top().first;
        PQ.pop();
        if (cost > B[ver]) continue;
        for (int i = 0; i < VERTEX[ver].size(); i++)
        {
            int nVer = VERTEX[ver][i].first;
            int nCost = VERTEX[ver][i].second;

            if (B[nVer] > cost + nCost)
            {
                B[nVer] = cost + nCost;
                PQ.push({ -B[nVer], nVer });
            }
        }
    }
}
void dijkstraC(int start)
{
    for (int i = 1; i <= N; i++)
    {
        C[i] = INT_MAX;
    }
    C[start] = 0;
    priority_queue<pair<int, int>> PQ;
    PQ.push({ 0, start });
    while (!PQ.empty())
    {
        int ver = PQ.top().second;
        int cost = -PQ.top().first;
        PQ.pop();
        if (cost > C[ver]) continue;
        for (int i = 0; i < VERTEX[ver].size(); i++)
        {
            int nVer = VERTEX[ver][i].first;
            int nCost = VERTEX[ver][i].second;

            if (C[nVer] > cost + nCost)
            {
                C[nVer] = cost + nCost;
                PQ.push({ -C[nVer], nVer });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    int a, b, c; cin >> a >> b >> c;
    cin >> M;

    int d, e, l;
    for (int i = 0; i < M; i++)
    {
        cin >> d >> e >> l;
        VERTEX[d].push_back({ e,l });
        VERTEX[e].push_back({ d,l });
    }
    dijkstraA(a);
    dijkstraB(b);
    dijkstraC(c);

    int ans;
    int mini = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == a || i == b || i == c) continue;
        if (mini < min(A[i], min(B[i], C[i])))
        {
            ans = i;
            mini = min(A[i], min(B[i], C[i]));
        }
    }
    cout << ans;
    return 0;
}