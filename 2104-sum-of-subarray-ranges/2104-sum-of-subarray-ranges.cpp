class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0LL;
        for(int i=0; i<n; i++){
            int mini=nums[i], maxi=nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j] > maxi) maxi=nums[j];
                else if(nums[j] < mini) mini=nums[j];
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};