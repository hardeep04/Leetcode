class Solution {
public:
    vector<int> NSE(vector<int> v){
        int n=v.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int> v){
        int n=v.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && v[st.top()] >= v[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int fun(vector<int> v, int c){
        int ans=0;
        vector<int> nse=NSE(v), pse=PSE(v);
        for(int i=0; i<c; i++){
            int val=(nse[i] - pse[i]-1) * v[i]; 
            ans = max(ans, val);   
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int r = mat.size(), c=mat[0].size();
        vector<int> v(c,0);
        int ans=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]=='1') v[j]+=1;
                else v[j]=0;
            }
            for(int k:v) cout<<k<<" ";
            cout<<endl;
            ans = max(ans,fun(v,c));
        }
        return ans;
    }
};