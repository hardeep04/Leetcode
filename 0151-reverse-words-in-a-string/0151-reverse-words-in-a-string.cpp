class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n= s.length();
        for(int i=0; i<n; ){
            string t="";
            while(i<n && s[i]==' ') i++;
            while(i<n && s[i]!=' '){
                t+=s[i];
                i++;
            }
            if(ans=="" && t!="") ans+=t;
            else if(t!="") ans = t+" "+ans;
        }
        return ans;
    }
};