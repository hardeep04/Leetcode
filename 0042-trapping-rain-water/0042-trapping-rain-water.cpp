class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int leftMax=h[0], rightMax=h[n-1];
        int l=0, r=n-1;
        int ans=0;
        while(l<r){
            if(leftMax <= rightMax){
                ans+=(leftMax - h[l]);
                l++;
                leftMax=max(leftMax, h[l]);
            }
            else{
                ans+=(rightMax - h[r]);
                r--;
                rightMax=max(rightMax, h[r]);
            }
        }
        return ans;
    }
};