class Solution {
public:
    int ans=0;
    int fun(vector<int> v){
        int x=0;
        for(auto &num:v) x^=num;
        return x;
    }
    void solve(vector<int>& nums, int i, vector<int> &v){
        if(i==nums.size()){
            ans+=fun(v);
            return;
        }
        v.push_back(nums[i]);
        solve(nums,i+1, v);
        v.pop_back();
        solve(nums,i+1, v);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> v;
        solve(nums,0,v);
        return ans;
    }
};