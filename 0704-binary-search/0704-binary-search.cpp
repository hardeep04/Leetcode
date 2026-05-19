class Solution {
public:
    int fun(vector<int> &nums, int target, int low, int high){
        if(low > high) return -1;
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return fun(nums,target,low,mid-1);
        else return fun(nums,target,mid+1,high);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return fun(nums,target,0,n-1);
    }
};