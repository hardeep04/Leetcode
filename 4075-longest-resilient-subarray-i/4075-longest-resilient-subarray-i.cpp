class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=1, curr=nums[0]%k, t=nums[0]%k, len=1;
        for(int i=1; i<n; i++){
            if(nums[i]%k == t) curr+=nums[i]%k, len++;
            else{
                t = nums[i]%k;
                curr = nums[i]%k;
                len=1;
            }
            if(curr%k == nums[i]%k) maxi = max(maxi, len);

        }
        return maxi;
    }
};
