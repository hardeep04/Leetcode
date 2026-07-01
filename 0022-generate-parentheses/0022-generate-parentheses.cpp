class Solution {
public:
    void fun(int n, vector<string> &v, string s, int open, int close){
        if(open>n || close>n || close>open) return;
        if(open==n && close==n){
            v.push_back(s);
            return;
        }
        fun(n,v,s+'(', open+1, close);
        fun(n,v,s+')', open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        fun(n, v, "",0,0);
        return v;
    }
};