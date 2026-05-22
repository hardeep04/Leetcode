class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > nums[n-1]){
                if(target > nums[mid] || target < nums[0]) left=mid+1;
                else right = mid-1;
            }
            else{
                if(target < nums[mid] || target > nums[n-1]) right = mid-1;
                else left=mid+1;
            }
        }
        return -1;
    }
};