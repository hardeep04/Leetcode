class Solution {
public:
    int fun(vector<int>& st, vector<vector<int>>& jobs, int i, vector<int>& dp){
        int n=st.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int index = lower_bound(st.begin(), st.end(), jobs[i][1]) - st.begin();
        int pick = jobs[i][2] + fun(st, jobs, index, dp);
        int notPick = fun(st, jobs, i+1, dp);
        return dp[i] = max(pick, notPick); 
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n, -1);
        vector<vector<int>> jobs(n);
        for(int i=0; i<n; i++){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        return fun(startTime, jobs, 0, dp);
    }
};