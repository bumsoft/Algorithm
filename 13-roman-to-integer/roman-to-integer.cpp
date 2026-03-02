class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        int prev_sum = m[s[0]];
        char prev = s[0];
        for(int i=1;i<s.size();i++)
        {
            if(m[prev] >= m[s[i]]) 
            {
                ans += prev_sum;
                prev_sum = m[s[i]];
                prev = s[i];
            }
            else
            {
                ans += m[s[i]] - prev_sum;
                prev_sum = 0;
                prev = s[i];
            }
        }
        ans += prev_sum;
        return ans;
    }
};