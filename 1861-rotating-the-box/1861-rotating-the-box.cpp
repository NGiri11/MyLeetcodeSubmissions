class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        for (int i = 0; i < m; ++i) {
            int emptySlot = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    emptySlot = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    boxGrid[i][j] = '.';
                    boxGrid[i][emptySlot] = '#';
                    emptySlot--;
                }
            }
        }
        vector<vector<char>> rotated(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        return rotated;
    }
};