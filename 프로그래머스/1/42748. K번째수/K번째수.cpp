#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(int i=0;i<commands.size();i++)
    {
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        temp = array;
        sort(temp.begin()+a-1, temp.begin()+b);
        answer.push_back(temp[a-2+c]);
    }
    
    
    return answer;
}