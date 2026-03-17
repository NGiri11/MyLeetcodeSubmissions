class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == 0) height[i][j] = 0;
                else height[i][j] = (i == 0 ? 1 : height[i-1][j] + 1);
            }
        }
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            vector<int> row = height[i];
            sort(row.begin(), row.end(), greater<int>());
            for (int k = 0; k < n; k++) {
                maxArea = max(maxArea, row[k] * (k + 1));
            }
        }
        return maxArea;
    }
};