class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length(), m=t.length();
        if(m!=n) return 0;
        map<char,char> mp, mp2;

        for(int i=0; i<n; i++){
            if(mp.find(s[i]) == mp.end() && mp2.find(t[i]) == mp2.end()){
                mp[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else{
                if(mp[s[i]] == t[i] && mp2[t[i]] == s[i]) continue;
                else return 0;
            }
        }
        return 1;
    }
};