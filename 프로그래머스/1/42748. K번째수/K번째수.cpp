#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++)
    {
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        priority_queue<int> PQ;
        for(int j=a-1;j<b;j++)
        {
            PQ.push(-array[j]);
        }
        while(c--)
        {
            if(c==0)
            {
                answer.push_back(-PQ.top());
                break;
            }
            PQ.pop();
        }
    }
    
    
    return answer;
}