class Solution {
public:
    int fun(vector<int>& nums, int low, int high){
        if(low==high) return nums[low];
        int mid = low + (high-low)/2;
        int left = fun(nums,low,mid);
        int right = fun(nums,mid+1,high);
        int crossSum = cross(nums,low,mid,high);
        return max({left,right,crossSum}); 
    }

    int cross(vector<int>& nums, int low, int mid, int high){
        int left=INT_MIN, sum1=0;
        for(int i=mid; i>=low; i--){
            sum1+=nums[i];
            left = max(left, sum1);
        }
        int right=INT_MIN, sum2=0;
        for(int i=mid+1; i<=high; i++){
            sum2+=nums[i];
            right = max(right, sum2);
        }
        return left+right;
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return fun(nums,0,n-1);
    }
};