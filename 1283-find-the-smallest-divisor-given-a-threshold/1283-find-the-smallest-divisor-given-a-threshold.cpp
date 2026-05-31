class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int n=nums.size();
        int l=1, r=*max_element(nums.begin(), nums.end());
        int ans=r;
        if(th == n) return r;
        while(l<=r){
            int mid = l +(r-l)/2;
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=nums[i]/mid;
                if(nums[i]%mid > 0) sum++;
            }
            if(sum<=th){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};