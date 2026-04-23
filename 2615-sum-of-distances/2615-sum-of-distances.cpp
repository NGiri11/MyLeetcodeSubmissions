class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        for (auto &entry : groups) {
            vector<int>& indices = entry.second;
            int k = indices.size();
            if (k == 1) continue;
            vector<long long> prefix(k + 1, 0);
            for (int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + indices[i];
            }
            for (int p = 0; p < k; p++) {
                int idx = indices[p];
                long long left = 1LL * idx * p - prefix[p];
                long long right = (prefix[k] - prefix[p + 1]) - 1LL * idx * (k - p - 1);
                ans[idx] = left + right;
            }
        }
        return ans;
    }
};
