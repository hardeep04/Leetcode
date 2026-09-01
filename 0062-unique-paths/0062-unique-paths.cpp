class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int N = m+n-2 , r=m-1;
        if(r > N-r) r=N-r;
        for (int i = 1; i <= r; ++i) {
            res = res * (N - i + 1) / i;
        }
        return (int)res;
    }
};