class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = min(k, m + n - 1);
        vector<vector<int>> prev_dp(n, vector<int>(k + 1, -1));
        for (int i = 0; i < m; ++i) {
            vector<vector<int>> curr_dp(n, vector<int>(k + 1, -1));
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    curr_dp[0][0] = 0;
                    continue;
                }
                int val = grid[i][j];
                int cost = (val > 0) ? 1 : 0;
                int score = val;
                for (int c = cost; c <= k; ++c) {
                    int best_score = -1;
                    if (i > 0 && prev_dp[j][c - cost] != -1) {
                        best_score = max(best_score, prev_dp[j][c - cost] + score);
                    }
                    if (j > 0 && curr_dp[j - 1][c - cost] != -1) {
                        best_score = max(best_score, curr_dp[j - 1][c - cost] + score);
                    }
                    curr_dp[j][c] = best_score;
                }
            }
            prev_dp = curr_dp;
        }
        int max_score = -1;
        for (int c = 0; c <= k; ++c) {
            max_score = max(max_score, prev_dp[n - 1][c]);
        }
        return max_score;
    }
};