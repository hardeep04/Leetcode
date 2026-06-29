class Solution {
public:
    int fun(string &s, int i, int sign, long long ans){
        int n=s.length();
        if(i>=n || !isdigit(s[i])) return ans*sign;
        ans = ans*10 + (s[i]-'0');
        if(sign==1 && ans >= INT_MAX) return INT_MAX;
        if(sign==-1 && -ans <= INT_MIN) return INT_MIN;

        return fun(s,i+1, sign, ans);
    }
    int myAtoi(string s) {
        int sign=1;
        int i=0, n=s.length();

        while(i<n && s[i]==' ') i++;
        
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+') i++;

        return fun(s,i,sign,0LL);
    }
};