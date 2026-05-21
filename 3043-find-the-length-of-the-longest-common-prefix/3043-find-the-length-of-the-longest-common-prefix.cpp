class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        int n=arr1.size(), m=arr2.size();
        for(int i=0; i<n; i++){
            int x = arr1[i];
            while(x){
                s.insert(x);
                x=x/10;
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            int x = arr2[i];
            while(x){
                if(s.find(x)!=s.end()){
                    int len = to_string(x).length();
                    ans = max(ans, len);
                    break;
                }
                x=x/10;
            }
        }
        return ans;
    }
};