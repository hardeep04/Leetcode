class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int ans=0, cnt=0;
        for(char c:s){
            if(c=='('){
                cnt++;
                ans = max(ans,cnt);
            }
            else if(c==')') cnt--;
        }
        return ans;
    }
};