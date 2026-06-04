class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I'] = 1, m['V']=5, m['X']=10, m['C']=100, m['M']=1000, m['L']=50, m['D']=500;
        int n=s.length();
        int ans=0;
        for(int i=0; i<n; i++){
            if(i<n-1 && m[s[i+1]] > m[s[i]]) ans-=m[s[i]];
            else ans+=m[s[i]];
        }
        return ans;
    }
};