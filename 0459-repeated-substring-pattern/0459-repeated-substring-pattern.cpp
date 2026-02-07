class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int> v;
        int m=n;
        for(int i=1; i<=m; i++){
            if(i==n) break; // for prime num
            if(n%i==0) v.push_back(i);
            if(m==n && v.size()>1) m=n/v[1];
        }
        cout<<v.size();
        for(int i=0; i<v.size(); i++){
            int len=v[i];
            string t = s.substr(0,len);
            bool ans=1;
            for(int j=len; j<n; j+=len){
                if(s.substr(j,len)!=t){
                    ans=0;
                    break;
                }
            }
            if(ans==1) return 1;
        }
        return 0;
    }
};