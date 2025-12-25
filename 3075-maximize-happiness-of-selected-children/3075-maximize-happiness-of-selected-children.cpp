class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        long long ans=0;
        sort(h.begin(), h.end(), greater<int>());
        int a=0;
        for(int i=0; i<n; i++){
            ans+=max(0,h[i]-a);
            a++;
            if(a==k) return ans;
        }
        return ans;
    }
};