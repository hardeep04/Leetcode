class Solution {
public:
    vector<int> NSE(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) ans[i]=n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NGE(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) ans[i]=n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSEE(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PGEE(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0, small=0, large=0;
        vector<int> psee=PSEE(nums), pgee=PGEE(nums), nse=NSE(nums), nge=NGE(nums);
        for(int i=0; i<n; i++){
            int left = i - psee[i], right = nse[i]-i;
            small += 1LL*left*right*nums[i];
            int l = i - pgee[i], r = nge[i]-i;
            large += 1LL*l*r*nums[i];
        }
        return large-small;
    }
};