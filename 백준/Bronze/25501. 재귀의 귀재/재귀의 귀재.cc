#include <bits/stdc++.h>
using namespace std;

int cnt;

int recursion(const char* s, int l, int r) { //문자열, 앞 인덱스, 뒷 인덱스
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else { cnt++; return recursion(s, l + 1, r - 1); }
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() 
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char t[1001];
        cin >> t;
        cnt = 1;
        cout << isPalindrome(t) << ' ' << cnt << '\n';
    }
}
