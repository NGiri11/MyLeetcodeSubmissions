class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        int minDist = INT_MAX;
        for (auto &entry : positions) {
            auto &indices = entry.second;
            if (indices.size() >= 3) {
                for (int j = 0; j + 2 < indices.size(); j++) {
                    int dist = 2 * (indices[j+2] - indices[j]);
                    minDist = min(minDist, dist);
                }
            }
        }
        return (minDist == INT_MAX) ? -1 : minDist;
    }
};