class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> v(k,0), v2(k,-1001);
        int n = energy.size();
        int j=k-1;
        for(int i=n-1; i>=0; i--){
            if(j==-1) j=k-1;
            v2[j] = max(v2[j], v[j]+energy[i]);
            v[j] += energy[i];
            j--;
        }
        return *max_element(v2.begin(), v2.end());
    }
};