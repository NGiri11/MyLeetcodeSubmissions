#include <vector>
class Solution {
private:
    int MOD = 1e9 + 7;
    int LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> pow2;
    void dfs(int node, int parent, int d) {
        depth[node] = d;
        up[node][0] = parent;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1);
            }
        }
    }
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; ++j) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; --j) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        adj.assign(n + 1, vector<int>());
        up.assign(n + 1, vector<int>(LOG, 1));
        depth.assign(n + 1, 0);
        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(1, 1, 0);
        for (int j = 1; j < LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        vector<int> answer;
        answer.reserve(queries.size());
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            if (u == v) {
                answer.push_back(0);
                continue;
            }
            int lca = get_lca(u, v);
            int k = depth[u] + depth[v] - 2 * depth[lca];
            answer.push_back(pow2[k - 1]);
        }
        return answer;
    }
};