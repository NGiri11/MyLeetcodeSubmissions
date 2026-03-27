class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int shiftedIndex;
                if (i % 2 == 0) {
                    shiftedIndex = (j + k) % n;
                } else {
                    shiftedIndex = (j - k + n) % n;
                }
                if (mat[i][j] != mat[i][shiftedIndex]) {
                    return false;
                }
            }
        }
        return true;
    }
};