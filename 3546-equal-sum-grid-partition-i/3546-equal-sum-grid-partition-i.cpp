class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }
        if (totalSum % 2 != 0) return false;
        long long target = totalSum / 2;
        long long prefix = 0;
        for (int i = 0; i < m - 1; i++) { 
            for (int j = 0; j < n; j++) {
                prefix += grid[i][j];
            }
            if (prefix == target) return true;
        }
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        prefix = 0;
        for (int j = 0; j < n - 1; j++) {
            prefix += colSum[j];
            if (prefix == target) return true;
        }
        return false;
    }
};