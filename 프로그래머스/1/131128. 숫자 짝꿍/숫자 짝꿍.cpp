#include <bits/stdc++.h>

using namespace std;

int cntX[10];
int cntY[10];
string solution(string X, string Y) {
    string answer = "";
    
    for(int i=0;i<X.size();i++)
    {
        cntX[X[i]-'0']++;
    }
    for(int i=0;i<Y.size();i++)
    {
        cntY[Y[i]-'0']++;
    }
    
    bool zck=0;
    for(int i=9;i>=0;i--)
    {
        while(min(cntX[i], cntY[i]))
        {
            answer+=i+'0';
            if(cntX[i] == min(cntX[i], cntY[i])) cntX[i]--;
            else cntY[i]--;
            if(i!=0) zck=1;
        }
    }
    if(answer.size()==0) return "-1";
    if(!zck) return "0";
    
    return answer;
}