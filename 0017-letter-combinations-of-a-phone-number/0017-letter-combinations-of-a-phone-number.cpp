class Solution {
public:
    void fun(string& digits, map<char,string>& m, vector<string>& ans, string temp, int ind){
        if(ind==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<m[digits[ind]].size(); i++){
            fun(digits, m, ans,temp+m[digits[ind]][i],ind+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> m={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ans;
        fun(digits, m, ans, "",0);
        return ans;
    }
};