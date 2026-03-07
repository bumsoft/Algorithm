#include <string>
#include <vector>

int A[] = {1,2,3,4,5}; int Alen = 5;
int B[] = {2,1,2,3,2,4,2,5}; int Blen = 8;
int C[] = {3,3,1,1,2,2,4,4,5,5}; int Clen = 10;

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a=0;
    int b=0;
    int c=0;
    int ac=0;
    int bc=0;
    int cc=0;
    
    for(int i=0;i<answers.size();i++)
    {
        int ans=answers[i];
        if(ans == A[ac%Alen]) a++;
        if(ans == B[bc%Blen]) b++;
        if(ans == C[cc%Clen]) c++;
        ac++;
        bc++;
        cc++;
    }
    int maxx = max(a,max(b,c));
    if(maxx==a) answer.push_back(1);
    if(maxx==b) answer.push_back(2);
    if(maxx==c) answer.push_back(3);
    
    return answer;
}