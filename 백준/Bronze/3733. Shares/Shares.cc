#include <iostream>
using namespace std;

int main()
{
    long long num, share, max;
    while (cin>>num) {
        cin >> share;
            if (num + 1 > share) {
                max = 0;
            }
            else {
                for (long long i = 1; i * (num + 1) <= share; i++)
                    max = i;
            }
            cout << max << "\n";
        
    }
    return 0;
}