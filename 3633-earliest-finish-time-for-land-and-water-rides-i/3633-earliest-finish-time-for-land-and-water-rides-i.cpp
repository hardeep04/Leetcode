class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mini=INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int t1,t2;
                t1 = landStartTime[i] + landDuration[i];
                if(waterStartTime[j] > t1) t1 = waterStartTime[j];
                t1 += waterDuration[j];

                t2 = waterStartTime[j] + waterDuration[j];
                if(landStartTime[i] > t2) t2 = landStartTime[i];
                t2 += landDuration[i];

                mini = min({mini, t1,t2});
            }
        }
        return mini;
    }
};