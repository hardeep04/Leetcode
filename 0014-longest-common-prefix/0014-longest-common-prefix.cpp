class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(), mini=INT_MAX;
        string ans="";
        for(int i=0; i<n; i++){
            int x = strs[i].length();
            mini = min(mini,x);
        }
        for(int i=0; i<mini; i++){
            char c=strs[0][i];
            for(int j=0; j<n; j++){
                if(c != strs[j][i]) return ans;
            }
            ans+=c;
        }
        return ans;
    }
};