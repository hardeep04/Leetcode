class Solution {
public:
    bool fun(vector<int> &v, int mid, int m, int k){
        int n=v.size();
        int c=0, b=0;
        for(int i=0; i<n; i++){
            if(v[i]<=mid){
                c++;
                if(c==k){
                    b++;
                    c=0;
                }
            }
            else c=0;
        }
        return b>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        int n=v.size();
        long long p=1LL*m*k;
        if(p>n) return -1;
        int l=*min_element(v.begin(), v.end());
        int r=*max_element(v.begin(), v.end());
        int ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(fun(v,mid,m,k)){
                ans = mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};