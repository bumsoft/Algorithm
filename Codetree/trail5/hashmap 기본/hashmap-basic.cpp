#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
        }
    }

    // Please write your code here.
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        if(cmd[i] == "add")
        {
            m[k[i]] = v[i];
        }
        else if(cmd[i] == "remove")
        {
            m.erase(k[i]);
        }
        else
        {
            cout << (m[k[i]] ? to_string(m[k[i]]) : "None")<<'\n';
        }
    }

    return 0;
}
