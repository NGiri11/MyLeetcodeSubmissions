class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> P(n, vector<long long>(n + 1, 0));
        for (int col = 0; col < n; ++col) {
            for (int h = 0; h < n; ++h) {
                P[col][h + 1] = P[col][h] + grid[h][col];
            }
        }
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));
        for (int c = 0; c <= n; ++c) {
            dp[0][c] = 0;
        }
        vector<long long> pref(n + 1, 0);
        vector<long long> suff(n + 1, 0);
        for (int j = 1; j <= n; ++j) {
            vector<vector<long long>> dp_next(n + 1, vector<long long>(n + 1, -INF));
            int col_idx = j - 1;
            for (int c = 0; c <= n; ++c) {
                long long mx_pref = -INF;
                for (int n_val = 0; n_val <= n; ++n_val) {
                    if (dp[n_val][c] > mx_pref) {
                        mx_pref = dp[n_val][c];
                    }
                    pref[n_val] = mx_pref;
                }
                long long mx_suff = -INF;
                suff[n] = -INF;
                for (int n_val = n - 1; n_val >= 0; --n_val) {
                    int p = n_val + 1;
                    long long val = dp[p][c] + max(0LL, P[col_idx][p] - P[col_idx][c]);
                    if (val > mx_suff) {
                        mx_suff = val;
                    }
                    suff[n_val] = mx_suff;
                }
                for (int n_val = 0; n_val <= n; ++n_val) {
                    long long v1 = pref[n_val] + max(0LL, P[col_idx][n_val] - P[col_idx][c]);
                    long long v2 = suff[n_val];
                    dp_next[c][n_val] = max(v1, v2);
                }
            }
            dp = move(dp_next);
        }
        long long ans = 0;
        for (int c = 0; c <= n; ++c) {
            ans = max(ans, dp[c][0]);
        }
        return ans;
    }
};