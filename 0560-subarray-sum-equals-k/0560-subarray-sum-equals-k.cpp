class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int prefsum=0, ans=0;
        m[0]=1;
        for(int i=0; i<n; i++){
            prefsum+=nums[i];
            if(m.find(prefsum-k)!=m.end()){
                ans+=m[prefsum-k];
            }
            m[prefsum]++;
        }
        return ans;
    }
};