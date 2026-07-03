class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<int> unique_costs;
        for (const auto& edge : edges) {
            unique_costs.push_back(edge[2]);
        }
        sort(unique_costs.begin(), unique_costs.end());
        unique_costs.erase(unique(unique_costs.begin(), unique_costs.end()), unique_costs.end());
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            adj[u].push_back({v, cost});
            in_degree[v]++;
        }
        vector<int> topo_order;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        auto isValid = [&](int X) -> bool {
            long long INF = 1e18;
            vector<long long> dp(n, INF);
            dp[0] = 0;
            for (int u : topo_order) {
                if (dp[u] == INF) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int cost = neighbor.second;
                    if (cost >= X) {
                        if (dp[u] + cost < dp[v]) {
                            dp[v] = dp[u] + cost;
                        }
                    }
                }
            }
            return dp[n - 1] <= k;
        };
        int low = 0, high = unique_costs.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(unique_costs[mid])) {
                ans = unique_costs[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};