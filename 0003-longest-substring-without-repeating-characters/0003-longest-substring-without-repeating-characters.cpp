class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n=s.length();
        // if(n==0) return 0;
        // int i=0,j=0, ans=1;
        // map<char, int> m; 
        // for(j=0; j<n; j++){
        //     if(m[s[j]]==1){
        //         ans = max(ans,j-i);
        //         while(m[s[j]]!=0){
        //             m[s[i]]--;
        //             i++;
        //         }
        //     }
        //     m[s[j]]++;
        // }
        // ans = max(ans,j-i);
        // return ans;

        // // method 2-- instead of storing freq of each char, we store their last seen index
        
        
        int n=s.length();
        if(n==0) return 0;
        int i=0, ans=1;
        vector<int> v(256,-1);
        for(int j=0; j<n; j++){
            if(v[s[j]]>=i) i=v[s[j]]+1;
            v[s[j]] = j;
            ans=max(ans, j-i+1);
        }
        return ans;
    }
};