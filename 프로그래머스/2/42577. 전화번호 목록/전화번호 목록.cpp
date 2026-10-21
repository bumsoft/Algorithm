#include <bits/stdc++.h>

// 길이가 짧은 순으로 map에 넣고, 넣을 때마다 해당 전화번호의 1자리, 2자리 , ... , 전부 까지 있는지 확인
// N * 20 * logN = NlogN.

using namespace std;

bool comp(string a, string b)
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    
    unordered_set<string> s;
    
    sort(phone_book.begin(), phone_book.end(), comp);
    
    for(string t : phone_book)
    {
        for(int i=0;i<t.size();i++)
        {
            if(s.count(t.substr(0,i+1)) != 0)
            {
                return false;
            }
        }
        s.insert(t);
    }
               
    return true;

}