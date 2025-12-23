class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int> &nums, int i){
        int n = nums.size();
        if(i==n-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<n; j++){
            swap(nums[j], nums[i]);            
            fun(nums,i+1);
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        fun(nums,0);
        return ans;
    }
};