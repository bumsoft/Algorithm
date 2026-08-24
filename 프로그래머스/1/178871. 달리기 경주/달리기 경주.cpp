#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> mp;
    for(int i=0;i<players.size();i++)
    {
        mp[players[i]] = i;
    }
    
    for(int i=0;i<callings.size();i++)
    {
        string a = callings[i];
        int a_idx = mp[a];
        
        string b = players[a_idx-1];
        int b_idx = a_idx-1;
        
        players[a_idx] = b;
        players[b_idx] = a;
        
        mp[a]= b_idx;
        mp[b] = a_idx;
    }
    
    
    
    return players;
}