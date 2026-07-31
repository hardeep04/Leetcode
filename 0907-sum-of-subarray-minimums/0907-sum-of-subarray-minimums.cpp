class Solution {
public:
    // next nearest smaller element
    vector<int> NSE(vector<int> arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // previous nearest smaller or equal element
    vector<int> PSEE(vector<int> arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n = arr.size();
        int ans=0;
        vector<int> psee = PSEE(arr), nse=NSE(arr);
        for(int i=0; i<n; i++){
            int left = i - psee[i], right = nse[i] - i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            ans = (ans + (freq*arr[i]*1LL) % mod) % mod;
        }
        return ans;
    }
};