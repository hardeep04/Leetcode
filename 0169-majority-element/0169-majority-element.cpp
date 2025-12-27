class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans=nums[0], a=1;
        for(int i=1; i<n; i++){
            if(nums[i]!=ans){
                a--;
                if(a==0){
                    ans = nums[i];
                    a=1;
                }
            }
            else{
                a++;
            }
        }
        int c=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ans) c++;
        }
        if(c>n/2) return ans;
        return -1;
    }
};