class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long sum=0LL, ans=0LL;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]-'0'){
                ans= ans*10 + (s[i]-'0');
                sum+=(s[i]-'0');
            }
        }
        return sum*ans;
    }
};