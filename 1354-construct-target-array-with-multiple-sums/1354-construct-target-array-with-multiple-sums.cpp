class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq(target.begin(), target.end());
        long long total = accumulate(target.begin(), target.end(), 0);
        while(pq.top()>1){
            int top = pq.top();
            pq.pop();
            long long sum = total-top;
            if(top<=sum || sum==0) return 0;
            int prev = top%sum;
            if(prev==0) prev=sum;
            pq.push(prev);
            total = sum+prev;
        }
        return 1;
    }
};