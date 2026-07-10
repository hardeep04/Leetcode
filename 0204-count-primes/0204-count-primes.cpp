class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0; 
        int c=0;
        vector<bool> v(n+1,1);
        v[0] = 0;
        v[1] = 0;
        for(int i=2; i<n; i++){
            if(v[i]){
                c++;
                for(int j=(i<<1); j<n; j+=i){
                    v[j]=0;
                }
            }
        }
        return c;
    }
};