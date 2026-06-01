class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        int level=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(level>0) ans+=s[i];
                level++;
            }
            else{
                level--;
                if(level>0) ans+=s[i];
            }
        }
        return ans;
    }
};