//'a', 'e', 'i', 'o', 'u'
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int ans;
    char str[300];
    while(true)
    {
        ans=0;
        cin.getline(str,300);
        

        if(str[0]=='#')
        {
            return 0;
        }
        for(int i=0;i<strlen(str);i++)
        {
            char a=str[i];
            if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U'||a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
                ans++;
        }
        cout<<ans<<'\n';
    }
}