class Solution {
public:
    bool ispalin(string s){
        int n=s.length();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-1-i]) return 0;
        } 
        return 1;
    }
    void fun(string& s, vector<vector<string>>&ans, vector<string>& v, string temp, int ind){
        if(ind==s.length()){
            ans.push_back(v);
            return ;
        }
        for(int i=ind; i<s.size(); i++){
            string t = s.substr(ind,i-ind+1);
            if(ispalin(t)){
                v.push_back(t);
                fun(s,ans,v,temp,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        fun(s,ans,v, "", 0);
        return ans;
    }
};