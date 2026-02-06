class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n=nums1.size(), m=nums2.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++) pq.push({nums1[i] + nums2[0], 0});

        while(k-- && !pq.empty()){
            int sum = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            ans.push_back({sum-nums2[pos], nums2[pos]});
            if(pos+1<m) pq.push({sum-nums2[pos] + nums2[pos+1], pos+1});
        }
        return ans;
    }
};