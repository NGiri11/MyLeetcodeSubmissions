class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const long long MOD = 1e9 + 7;
        vector<long long> dpMax(n, 0), dpMin(n, 0);
        dpMax[0] = dpMin[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dpMax[j] = dpMin[j] = dpMax[j-1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            dpMax[0] = dpMin[0] = dpMax[0] * grid[i][0];
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];
                long long maxPrev = max(dpMax[j], dpMax[j-1]);
                long long minPrev = min(dpMin[j], dpMin[j-1]);
                long long newMax = max({val * maxPrev, val * minPrev});
                long long newMin = min({val * maxPrev, val * minPrev});
                dpMax[j] = newMax;
                dpMin[j] = newMin;
            }
        }
        long long ans = dpMax[n-1];
        return ans < 0 ? -1 : ans % MOD;
    }
};