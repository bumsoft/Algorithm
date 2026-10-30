#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size()==1)
    {
        arr[0]=-1;
        return arr;
    }
    int min_=arr[0];
    int idx=0;
    for(int i=1;i<arr.size();i++)
    {
        if(min_ > arr[i])
        {
            min_ = arr[i];
            idx=i;
        }
    }
    arr.erase(arr.begin()+idx);
    
    return arr;
}