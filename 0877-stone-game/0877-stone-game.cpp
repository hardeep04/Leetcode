class Solution {
public:
    int dp[501][501][2];
    int fun(vector<int> &v, int i, int j, int turn){
        if(i>j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        if(turn==0){
            return dp[i][j][turn] = max(v[i] + fun(v,i+1,j,1), v[j] + fun(v,i,j-1, 1));
        }
        else 
            return dp[i][j][turn] = min(fun(v,i+1,j,0), fun(v,i,j-1, 0));
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        int total = accumulate(piles.begin(), piles.end(), 0);
        return fun(piles, 0, n-1, 0) >= (total>>1);
    }
};