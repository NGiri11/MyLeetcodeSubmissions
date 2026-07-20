class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        k = k % total;
        if (k == 0) return grid;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int p = 0; p < total; ++p) {
            int orig_p = (p - k + total) % total;
            result[p / n][p % n] = grid[orig_p / n][orig_p % n];
        }
        
        return result;
    }
};