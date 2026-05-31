class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=*max_element(weights.begin(), weights.end());
        int r=accumulate(weights.begin(), weights.end(), 0);
        int ans=r;
        while(l<=r){
            int mid = l+(r-l)/2;
            int curr=0, d=0;
            bool b = 1;
            for(int i=0; i<n; i++){
                if(curr+weights[i]>mid){
                    d++;
                    curr=0;
                    if(d>days){
                        b=0; break;
                    }
                }
                curr+=weights[i];
            }
            if(curr>0) d++;
            if(d>days) b=0;
            if(b){
                ans = mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};