class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        auto rotate = [&](vector<vector<int>>& m) {
            vector<vector<int>> res(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[j][n - 1 - i] = m[i][j];
                }
            }
            m = res;
        };
        for (int k = 0; k < 4; k++) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};