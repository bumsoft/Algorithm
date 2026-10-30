#include <bits/stdc++.h>

using namespace std;

bool sk[30];

string solution(string s, string skip, int index) {
    for(char s : skip)
    {
        sk[s-'a']=1;
    }
    for(int i=0;i<s.size();i++)
    {
        int t = s[i]-'a';
        int cnt = index;
        while(cnt)
        {
            t++;
            t%='z'-'a'+1;
            if(sk[t]) {continue;}
            //cout<< (char)(t+'a')<<"셈\n";
            cnt--;
        }
        s[i] = t+'a';
        //cout<<s[i]<<'\n';
    }
    return s; // u v w x y z a
}