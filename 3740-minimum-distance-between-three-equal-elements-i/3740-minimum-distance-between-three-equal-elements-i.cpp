class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto& [val, indices] : mp) {
            int m = indices.size();
            if (m < 3) continue;
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    for (int k = j + 1; k < m; k++) {
                        int dist = 2 * (indices[k] - indices[i]);
                        ans = min(ans, dist);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};