class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        int j=1;
        sort(nums.begin(), nums.end());
        int ans=n;
        for(int i=0; i<n; i++){
            while(j<n && nums[j] <= static_cast<long long>(k)*nums[i]) j++;
            ans = min(ans, n-j+i);
        }
        return ans;
    }
};