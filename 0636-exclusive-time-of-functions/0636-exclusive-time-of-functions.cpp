class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);

        stack<int> id;
        stack<int> start;
        stack<int> to_skip;

        for (string log : logs) {
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            int fid = stoi(log.substr(0, p1));
            string type = log.substr(p1 + 1, p2 - p1 - 1);
            int time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                id.push(fid);
                start.push(time);
                to_skip.push(0);
            } 
            else {
                int st = start.top(); start.pop();
                int skip = to_skip.top(); to_skip.pop();

                int total_time = time - st + 1;
                int exclusive_time = total_time - skip;

                ans[id.top()] += exclusive_time;
                id.pop();

                if (!to_skip.empty()) {
                    to_skip.top() += total_time;
                }
            }
        }
        return ans;
    }
};