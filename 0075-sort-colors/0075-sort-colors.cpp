class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) swap(nums[i],nums[l++]);
        }
        for(int i=l; i<n; i++){
            if(nums[i]==1) swap(nums[i],nums[l++]);
        }
    }
};