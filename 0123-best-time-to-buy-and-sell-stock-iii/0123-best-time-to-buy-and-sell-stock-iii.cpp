class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        vector<int> left(n), right(n);
        left[0]=0;
        int mini = prices[0];
        for(int i=1; i<n; i++){
            if(prices[i] < mini) mini = prices[i], left[i] = left[i-1];
            else left[i] = max(left[i-1], prices[i]-mini);
        }
        right[n-1]=0;
        int maxi = prices[n-1];
        for(int i=n-2; i>=0; i--){
            if(prices[i] > maxi) maxi = prices[i], right[i] = right[i+1];
            else right[i] = max(right[i+1], maxi - prices[i]);
        }
        for(int i=0; i<n; i++){
            ans = max(ans, left[i]+right[i]);
        }
        return ans;
    }
};