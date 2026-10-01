class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // int dp[n+1][2];
        // memset(dp, 0, sizeof(dp));
        vector<int> prev(2,0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(2);
            int left = -prices[i] + prev[0];
            int right = prev[1];
            curr[1] = max(left, right);
                
            int l = prices[i] - fee + prev[1];
            int r = prev[0];
            curr[0] = max(l, r);
            prev = curr;
        }
        return prev[1];
    }
};