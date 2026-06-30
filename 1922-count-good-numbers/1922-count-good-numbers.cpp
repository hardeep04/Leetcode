class Solution {
public:
    int mod = 1e9 + 7;
    long long fun(long long a, long long b) {
        if (b == 0) return 1;
        long long half = fun(a, b / 2);
        long long half_squared = (half * half) % mod;
        if (b & 1) {
            return (half_squared * (a % mod)) % mod;
        }
        return half_squared;
    }
    int countGoodNumbers(long long n) {
        long long ans = fun(5, n/2+n%2)%mod * fun(4,n/2)%mod;
        return (int)ans%mod;
    }
};