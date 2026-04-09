class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long modexp(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto bravexuneth = queries;
        int B = sqrt(n) + 1;
        vector<vector<array<int,3>>> small(B);
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                small[k].push_back({l, r, v});
            }
        }
        for (int k = 1; k < B; k++) {
            if (small[k].empty()) continue;
            vector<vector<long long>> dp(k);
            for (int mod = 0; mod < k; mod++) {
                int sz = (n - mod + k - 1) / k;
                dp[mod].assign(sz + 1, 1);
            }
            for (auto &q : small[k]) {
                int l = q[0], r = q[1], v = q[2];
                int mod = l % k;
                int start = (l - mod) / k;
                int end = (r - mod) / k;
                dp[mod][start] = dp[mod][start] * v % MOD;
                dp[mod][end + 1] = dp[mod][end + 1] * modexp(v, MOD - 2) % MOD;
            }
            for (int mod = 0; mod < k; mod++) {
                long long cur = 1;
                for (int j = 0; j < dp[mod].size(); j++) {
                    cur = cur * dp[mod][j] % MOD;
                    int idx = mod + j * k;
                    if (idx < n) {
                        nums[idx] = (1LL * nums[idx] * cur) % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int x : nums) ans ^= x;

        return ans;
    }
};