class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min-priority queue storing: {accumulated_weight, current_node, consecutive_count}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        // visited[node][count] to store the minimum weight to reach this state
        vector<vector<long long>> min_weight(n, vector<long long>(k + 1, -1));

        pq.push({0, 0, 1});
        min_weight[0][1] = 0;

        while (!pq.empty()) {
            auto [w, curr, count] = pq.top();
            pq.pop();

            if (curr == n - 1) return w;

            if (min_weight[curr][count] != -1 && w > min_weight[curr][count]) continue;

            for (auto& edge : adj[curr]) {
                int v = edge.first;
                int weight = edge.second;

                int next_count = (labels[curr] == labels[v]) ? count + 1 : 1;

                if (next_count > k) continue;

                long long next_weight = w + weight;

                if (min_weight[v][next_count] == -1 || next_weight < min_weight[v][next_count]) {
                    min_weight[v][next_count] = next_weight;
                    pq.push({next_weight, v, next_count});
                }
            }
        }

        return -1;
    }
};