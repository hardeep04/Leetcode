class Solution {
public:
    long long getDescentPeriods(vector<int>& v) {
        int n = v.size();
        long long ans=0;
        long long r=1;
        for(int i=0; i<n-1; i++){
            if(v[i] - v[i+1]==1) r++;
            else{
                ans += r*(r+1)/2;    
                r=1;
            }
        }
        if(r==1) ans+=1;
        else if(r>1) ans += r*(r+1)/2; 
        return ans;
    }
};