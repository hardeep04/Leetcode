class Solution {
public:
    bool fun(string &s, int l, int r){
        int n=s.length();
        while(l<n && !isalnum(s[l])) l++;
        while(r>=0 && !isalnum(s[r])) r--;
        if(l>=r) return 1;
        if(tolower(s[l])!=tolower(s[r])) return 0;
        return fun(s,l+1,r-1);
    }
    bool isPalindrome(string s) {
        return fun(s,0,s.length()-1);
    }
};