class Solution {
public:
    bool fun(string s, unordered_set<string>& dict, int i, vector<int>& dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(dict.find(temp)!=dict.end()){
                if(fun(s,dict,j+1,dp)) return dp[i] = 1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(301,-1);
        return fun(s,dict, 0, dp);
    }
};