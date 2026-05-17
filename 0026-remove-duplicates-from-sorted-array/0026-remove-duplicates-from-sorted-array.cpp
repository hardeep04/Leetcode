class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int a = INT_MIN, idx=0, k=0;
        for(int i=0; i<n; i++){
            if(nums[i]>a){
                a = nums[i];
                swap(nums[i], nums[idx++]);
                k++;
            }
        }
        return k;
    }
};