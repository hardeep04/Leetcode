class Solution {
public:
    void fun(int k, int target, vector<vector<int>>& ans, vector<int> temp, int ind){
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || k==0 || ind==9) return;
        
        for(int i=ind; i<9; i++){
            if(target>=i+1){
                temp.push_back(i+1);
                fun(k-1, target-(i+1), ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(k,n, ans, temp, 0);
        return ans;
    }   
};