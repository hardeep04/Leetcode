class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0, n=nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) c++;
            if(c==2) return 0;
        }
        if(c<2 && nums[0]>=nums[n-1]) return 1;
        if(c==0) return 1;
        return 0;
    }
};