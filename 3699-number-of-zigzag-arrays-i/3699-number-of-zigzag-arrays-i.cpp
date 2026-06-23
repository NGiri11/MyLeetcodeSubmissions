class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        int K = r - l + 1;
        vector<vector<long long>> dp(K, vector<long long>(2, 0));
        vector<vector<long long>> next_dp(K, vector<long long>(2, 0));
        for (int j = 0; j < K; ++j) {
            dp[j][0] = j;
            dp[j][1] = (K - 1) - j;
        }
        for (int i = 3; i <= n; ++i) {
            long long running_inc_sum = 0;
            for (int j = 0; j < K; ++j) {
                next_dp[j][0] = running_inc_sum;
                running_inc_sum = (running_inc_sum + dp[j][1]) % MOD;
            }
            long long running_dec_sum = 0;
            for (int j = K - 1; j >= 0; --j) {
                next_dp[j][1] = running_dec_sum;
                running_dec_sum = (running_dec_sum + dp[j][0]) % MOD;
            }
            dp = next_dp;
        }
        long long total_arrays = 0;
        for (int j = 0; j < K; ++j) {
            total_arrays = (total_arrays + dp[j][0] + dp[j][1]) % MOD;
        }
        return total_arrays;
    }
};