class Solution {
public:
    int fun(string &s, int l, int r){
        int n=s.length();
        while(l>=0 && r<=n-1 && s[l]==s[r]){
            l--; r++;
        }
        // return (r-1)-(l+1)+1;
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int start=0, end=0;
        for(int i=0; i<n; i++){
            int odd = fun(s,i,i);
            int even = fun(s,i,i+1);
            int len=max(odd,even);
            if(len >= end-start+1){
                start = i - ((len-1)>>1);
                end = i + (len>>1);
            }
        }
        return s.substr(start,end-start+1);
    }
};