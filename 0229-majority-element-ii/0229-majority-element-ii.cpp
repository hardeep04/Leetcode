class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int ans1=INT_MIN,ans2=INT_MIN;
        int c1=0,c2=0;

        for(int ele : nums){
            if(c1==0 && ele!=ans2){
                ans1 = ele;
                c1=1;
            }
            else if(c2==0 && ele!=ans1){
                ans2 = ele;
                c2=1;
            }
            else if(ele == ans1) c1++;
            else if(ele == ans2) c2++;
            else c1--,c2--;
        }
        c1=c2=0;
        for(int ele:nums){
            if(ele == ans1) c1++;
            if(ele == ans2) c2++;
        }
        if(c1>n/3) ans.push_back(ans1);
        if(c2>n/3 && ans1!=ans2) ans.push_back(ans2);
        return ans;
    }
};