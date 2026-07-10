class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> unique_vals = nums;
        sort(unique_vals.begin(), unique_vals.end());
        unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
        int U = unique_vals.size();
        vector<int> go_right(U);
        for (int i = 0; i < U; ++i) {
            long long target = (long long)unique_vals[i] + maxDiff;
            auto it = upper_bound(unique_vals.begin(), unique_vals.end(), target);
            go_right[i] = distance(unique_vals.begin(), it) - 1;
        }
        int LOG = 18; 
        vector<vector<int>> up(LOG, vector<int>(U));
        for (int i = 0; i < U; ++i) {
            up[0][i] = go_right[i];
        }
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < U; ++i) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int x = nums[u];
            int y = nums[v];
            if (x == y) {
                ans.push_back(1);
                continue;
            }
            if (x > y) swap(x, y);
            int idx_x = lower_bound(unique_vals.begin(), unique_vals.end(), x) - unique_vals.begin();
            int idx_y = lower_bound(unique_vals.begin(), unique_vals.end(), y) - unique_vals.begin();
            int max_reach = idx_x;
            for (int j = LOG - 1; j >= 0; --j) {
                max_reach = up[j][max_reach];
            }
            if (max_reach < idx_y) {
                ans.push_back(-1);
                continue;
            }
            int jumps = 0;
            int curr = idx_x;
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][curr] < idx_y) {
                    curr = up[j][curr];
                    jumps += (1 << j);
                }
            }
            jumps += 1;
            ans.push_back(jumps);
        }
        return ans;
    }
};