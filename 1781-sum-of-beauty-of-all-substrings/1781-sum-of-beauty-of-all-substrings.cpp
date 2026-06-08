class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        long ans=0;
        vector<vector<int>> freq(n+1, vector<int>(26,0));
        freq[1][s[0]-'a'] = 1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<26; j++){
                if(j==s[i-1]-'a') freq[i][j] = 1 + freq[i-1][j];
                else freq[i][j] = freq[i-1][j];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                int maxi=-1, mini=INT_MAX;
                for(int k=0; k<26; k++){
                    int diff = freq[j][k] - freq[i-1][k];
                    if(diff > maxi) maxi = diff;
                    if(diff < mini && diff >0) mini = diff;
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};