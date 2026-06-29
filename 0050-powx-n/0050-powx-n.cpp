class Solution {
public:
    double fun(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        if((n&1)==0){
            x=x*x;
            n=n>>1;
        }
        return x*fun(x,n-1);
    }
    double myPow(double x, int n) {
        double ans=0;
        if(n<0){
            x=1/x;
            ans=x*fun(x,abs(n+1));
        }
        else{
            ans=fun(x,n);
        }
        return ans;
    }
};