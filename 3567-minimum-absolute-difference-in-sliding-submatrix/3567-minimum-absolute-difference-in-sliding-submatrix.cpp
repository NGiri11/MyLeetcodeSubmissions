class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> values;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        values.push_back(grid[x][y]);
                    }
                }
                sort(values.begin(), values.end());
                int minDiff = INT_MAX;
                for (int idx = 1; idx < values.size(); idx++) {
                    if (values[idx] != values[idx - 1]) {
                        minDiff = min(minDiff, values[idx] - values[idx - 1]);
                    }
                }
                ans[i][j] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }
        return ans;
    }
};