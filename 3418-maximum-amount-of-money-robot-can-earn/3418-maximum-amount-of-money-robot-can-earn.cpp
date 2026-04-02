class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const int NEG = -1e9;
        vector<vector<int>> prev(n, vector<int>(3, NEG)), curr(n, vector<int>(3, NEG));
        for (int k = 0; k < 3; k++) {
            if (coins[0][0] >= 0) {
                prev[0][k] = coins[0][0];
            } else {
                prev[0][k] = coins[0][0];
                if (k > 0)
                    prev[0][k] = max(prev[0][k], 0);
            }
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                if (coins[0][j] >= 0) {
                    prev[j][k] = prev[j-1][k] + coins[0][j];
                } else {
                    int take_loss = prev[j-1][k] + coins[0][j];
                    int neutralize = (k > 0 ? prev[j-1][k-1] : NEG);
                    prev[j][k] = max(take_loss, neutralize);
                }
            }
        }
        for (int i = 1; i < m; i++) {
            curr.assign(n, vector<int>(3, NEG));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    int best_prev = NEG;
                    if (i > 0) best_prev = max(best_prev, prev[j][k]);
                    if (j > 0) best_prev = max(best_prev, curr[j-1][k]);
                    if (coins[i][j] >= 0) {
                        curr[j][k] = best_prev + coins[i][j];
                    } else {
                        int take_loss = best_prev + coins[i][j];
                        int neutralize = NEG;
                        if (k > 0) {
                            int best_prev_k_1 = NEG;
                            if (i > 0) best_prev_k_1 = max(best_prev_k_1, prev[j][k-1]);
                            if (j > 0) best_prev_k_1 = max(best_prev_k_1, curr[j-1][k-1]);
                            neutralize = best_prev_k_1;
                        }
                        curr[j][k] = max(take_loss, neutralize);
                    }
                }
            }
            prev = curr;
        }
        return max({prev[n-1][0], prev[n-1][1], prev[n-1][2]});
    }
};