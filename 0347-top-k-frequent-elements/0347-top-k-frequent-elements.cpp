class Solution {
public:
    struct comp {
        unordered_map<int, int>& m;
        comp(unordered_map<int, int>& mp) : m(mp){}

        bool operator()(int a, int b) const {
            return m[a] > m[b];
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        priority_queue<int, vector<int>, comp> pq(comp{m});

        for(auto &p:m){
            pq.push(p.first);
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};