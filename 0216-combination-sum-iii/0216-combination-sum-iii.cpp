class Solution {
public:
    void fun(vector<int> &v, int k, int target, vector<vector<int>>& ans, vector<int> temp, int i){
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || k==0 || i==9) return;
        temp.push_back(v[i]);
        fun(v,k-1, target-v[i], ans, temp, i+1);
        temp.pop_back();

        fun(v,k, target, ans, temp, i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v = {1,2,3,4,5,6,7,8,9}, temp;
        vector<vector<int>> ans;
        fun(v,k,n, ans, temp, 0);
        return ans;
    }   
};