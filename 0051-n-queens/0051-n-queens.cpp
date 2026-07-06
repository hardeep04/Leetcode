class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string> &v, int n, int row, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2){
        if(row==n){
            ans.push_back(v);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }

            v[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            solve(ans, v, n, row+1, cols, diag1, diag2);

            v[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n, string(n, '.'));
        
        vector<bool> cols(n, 0);
        vector<bool> diag1(2 * n - 1, 0);
        vector<bool> diag2(2 * n - 1, 0);
        
        solve(ans,v,n,0, cols, diag1, diag2);
        return ans;
    }
};