class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.length();
        for(int i=0; i<n; i++){
            while(!st.empty() && num[i] < st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }        
        while(k--){
            st.pop();
        }
        string s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        if(s=="") return "0";
        reverse(s.begin(), s.end());
        while(s.length()>1 && s[0]=='0') s.erase(s.begin());
        return s;
    }
};