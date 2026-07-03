class Solution {
public:
    void fun(vector<int> &arr, vector<vector<int>>& ans, vector<int> temp, int ind){
        ans.push_back(temp);
        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            fun(arr,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        fun(nums,ans, temp, 0);
        return ans;
    }
};