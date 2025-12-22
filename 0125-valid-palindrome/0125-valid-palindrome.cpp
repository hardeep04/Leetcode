class Solution {
public:
    bool fun(string &s, int l, int r){
        int n = s.length();
        if(l>=r) return 1;
        if(l<n && r>=0 && s[l] != s[r]) return 0;
        return fun(s,l+1,r-1);
    }
    bool isPalindrome(string s) {
        string str="";
        for(char c:s){
            if(isalnum(c)) str+=tolower(c);
        }
        int n = str.length();
        return fun(str,0,n-1);
    }
};