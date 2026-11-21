#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;

int seg[100'000 << 2];

int init(int node, int s, int e)
{
    if (s == e)
    {
        cin >> seg[node];
        return seg[node];
    }
    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);
    return seg[node] = min(left, right);
}

int query(int node, int s, int e, int a, int b)
{
    if (a <= s && b >=e)
    {
        return seg[node];
    }
    if (b < s || a > e) return INT_MAX;

    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, a, b);
    int right = query(node * 2 + 1, mid + 1, e, a, b);
    return min(left, right);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    init(1, 1, N);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << query(1, 1, N, a, b) << '\n';
    }

    return 0;
}