class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        long long lsum=accumulate(nums.begin(), nums.end(), 0LL), rprod=1;
        for(int i=n-1; i>=0; i--){
            lsum-=nums[i];
            if(lsum==rprod) return i;
            if( i>0 && ((lsum-nums[i-1])/nums[i])  < rprod) break;
            rprod = rprod * (long long)nums[i];
        }
        return -1;
    }
};