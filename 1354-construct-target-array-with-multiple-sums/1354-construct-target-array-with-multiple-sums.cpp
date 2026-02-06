class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long long total = accumulate(target.begin(), target.end(), 0LL);
        while(pq.top()>1){
            long long top = pq.top();
            pq.pop();
            long long sum = total-top;
            if(top<=sum || sum==0) return 0;
            long long prev = top%sum;
            if(prev==0) prev=sum;
            pq.push(prev);
            total = sum+prev;
        }
        return 1;
    }
};