class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int i=0,j=0, ans=1;
        map<char, int> m;
        for(j=0; j<n; j++){
            if(m[s[j]]==1){
                ans = max(ans,j-i);
                while(m[s[j]]!=0){
                    m[s[i]]--;
                    i++;
                }
            }
            m[s[j]]++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};