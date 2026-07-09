class Solution {
public:
    void fun(string s, int target, vector<string>& ans, string exp, int i, long long curr, long long last){
        if(i==s.size()){
            if(target == curr) ans.push_back(exp);
            return;
        }
        for(int j=i; j<s.size(); j++){
            if (j > i && s[i] == '0') return;
            string current = s.substr(i, j-i+1);
            long long val = stoll(current);
            if(i==0) fun(s,target,ans,current, j+1, val,val);
            else{
                fun(s,target,ans,exp+'+'+current, j+1, curr+val,val);
                fun(s,target,ans,exp+'-'+current, j+1, curr-val,-val);
                fun(s,target,ans,exp+'*'+current, j+1, curr-last+last*val,last*val);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        fun(num, target, ans, "", 0, 0, 0);
        return ans;
    }
};