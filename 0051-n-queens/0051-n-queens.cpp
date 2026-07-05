class Solution {
public:
    bool isvalid(vector<string> &v, int n, int row, int col){
        for(int i=0; i<row; i++){
            if(v[i][col] == 'Q') return 0;
        }
        for(int i=row,j=col; i>=0 && j>=0; i--,j--){
            if(v[i][j] == 'Q') return 0;
        }
        for(int i=row,j=col; i>=0 && j<n; i--,j++){
            if(v[i][j] == 'Q') return 0;
        }
        return 1;
    }
    void solve(vector<vector<string>>& ans, vector<string> &v, int n, int row){
        if(row==n){
            ans.push_back(v);
            return;
        }
        for(int col=0; col<n; col++){
            if(isvalid(v,n,row,col)){
                v[row][col] = 'Q';
                solve(ans,v,n,row+1);
                v[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v;
        
        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<n; j++){
                s+='.';
            }
            v.push_back(s);
        }
        solve(ans,v,n,0);
        return ans;
    }
};