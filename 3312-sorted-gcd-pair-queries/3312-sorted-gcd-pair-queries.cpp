class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<long long> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        vector<long long> cnt(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                cnt[i] += freq[j];
            }
        }
        vector<long long> exact_gcd(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long total_pairs = cnt[i] * (cnt[i] - 1) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= exact_gcd[j];
            }
            exact_gcd[i] = total_pairs;
        }
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + exact_gcd[i];
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        return ans;
    }
};