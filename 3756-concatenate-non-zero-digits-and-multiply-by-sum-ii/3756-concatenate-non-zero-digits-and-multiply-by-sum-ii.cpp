class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int m = s.length();
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };
        vector<long long> pow10(m + 1, 1);
        vector<long long> powInv10(m + 1, 1);
        long long INV_10 = power(10, MOD - 2);
        for (int i = 1; i <= m; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
            powInv10[i] = (powInv10[i - 1] * INV_10) % MOD;
        }
        vector<int> pref_N(m + 1, 0);
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_X(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            pref_N[i + 1] = pref_N[i] + (digit != 0 ? 1 : 0);
            pref_sum[i + 1] = pref_sum[i] + digit;
            if (digit != 0) {
                long long current_contrib = (digit * powInv10[pref_N[i + 1]]) % MOD;
                pref_X[i + 1] = (pref_X[i] + current_contrib) % MOD;
            } else {
                pref_X[i + 1] = pref_X[i];
            }
        }
        vector<int> answer;
        answer.reserve(queries.size());
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            long long current_sum = pref_sum[r + 1] - pref_sum[l];
            long long raw_X = (pref_X[r + 1] - pref_X[l] + MOD) % MOD;
            long long x = (raw_X * pow10[pref_N[r + 1]]) % MOD;
            long long current_ans = (x * current_sum) % MOD;
            answer.push_back(current_ans);
        }
        return answer;
    }
};