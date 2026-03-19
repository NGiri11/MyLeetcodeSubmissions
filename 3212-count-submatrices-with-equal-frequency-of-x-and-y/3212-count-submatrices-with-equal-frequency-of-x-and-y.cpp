class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefX(n+1, vector<int>(m+1, 0));
        vector<vector<int>> prefY(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefX[i+1][j+1] = prefX[i+1][j] + prefX[i][j+1] - prefX[i][j] + (grid[i][j] == 'X');
                prefY[i+1][j+1] = prefY[i+1][j] + prefY[i][j+1] - prefY[i][j] + (grid[i][j] == 'Y');
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int xCount = prefX[i+1][j+1];
                int yCount = prefY[i+1][j+1];
                if (xCount > 0 && xCount == yCount) {
                    count++;
                }
            }
        }
        return count;
    }
};