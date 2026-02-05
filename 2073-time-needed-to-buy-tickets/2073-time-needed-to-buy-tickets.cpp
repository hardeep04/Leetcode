class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        int n = tickets.size();
        for(int i=0; i<100; i++){
            for(int j=0; j<n; j++){
                if(tickets[j]>0){
                    tickets[j]--;
                    ans++;
                }
                if(tickets[k]==0) return ans;
            }
        }
        return ans;
    }
};