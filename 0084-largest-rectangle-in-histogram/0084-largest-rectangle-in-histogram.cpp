class Solution {
public:
    vector<int> PSE(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSE(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ans[i]=n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) {
        vector<int> pse=PSE(h), nse=NSE(h);
        int n=h.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int val = h[i]*(nse[i] - pse[i]-1);
            ans = max(ans,val);
        }
        return ans;
    }
};