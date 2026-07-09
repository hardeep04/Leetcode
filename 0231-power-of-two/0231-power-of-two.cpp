class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return 0;
        int c=0;
        while(n){
            n=n&(n-1);
            c++;
        }
        return c==1;
    }
};