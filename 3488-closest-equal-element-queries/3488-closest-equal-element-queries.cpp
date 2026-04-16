class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        vector<int> ans;
        for (int q : queries) {
            int val = nums[q];
            auto &indices = pos[val];
            if (indices.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int idx = lower_bound(indices.begin(), indices.end(), q) - indices.begin();
            int best = INT_MAX;
            if (idx > 0) {
                int j = indices[idx - 1];
                int dist = min(abs(q - j), n - abs(q - j));
                best = min(best, dist);
            }
            if (idx < (int)indices.size() - 1) {
                int j = indices[idx + 1];
                int dist = min(abs(q - j), n - abs(q - j));
                best = min(best, dist);
            }
            if (idx < (int)indices.size() && indices[idx] == q) {
                int j = indices[(idx - 1 + indices.size()) % indices.size()];
                int dist = min(abs(q - j), n - abs(q - j));
                best = min(best, dist);
                j = indices[(idx + 1) % indices.size()];
                dist = min(abs(q - j), n - abs(q - j));
                best = min(best, dist);
            }
            ans.push_back(best);
        }
        return ans;
    }
};