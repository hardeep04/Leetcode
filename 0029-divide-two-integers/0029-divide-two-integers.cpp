class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor==-1) return INT_MAX;
        bool neg=(dividend<0) ^ (divisor<0);
        long long num = dividend, d=divisor;
        num = abs(num);
        d = abs(d);
        long long ans=0;
        for(int i=31; i>=0; i--){
            if((d<<i)<=num){
                num-=(d<<i);
                ans+=(1LL<<i);
            }
        }
        if(neg) return -ans;
        return ans;
    }
};