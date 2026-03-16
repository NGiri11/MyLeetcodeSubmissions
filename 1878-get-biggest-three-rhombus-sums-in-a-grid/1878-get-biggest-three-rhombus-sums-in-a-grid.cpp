class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                s.insert(grid[r][c]); // size 0 rhombus

                for (int k = 1; r + 2*k < m && c - k >= 0 && c + k < n; k++) {

                    int sum = 0;

                    int x = r, y = c;

                    // top -> right
                    for (int i = 0; i < k; i++)
                        sum += grid[x + i][y + i];

                    // right -> bottom
                    for (int i = 0; i < k; i++)
                        sum += grid[x + k + i][y + k - i];

                    // bottom -> left
                    for (int i = 0; i < k; i++)
                        sum += grid[x + 2*k - i][y - i];

                    // left -> top
                    for (int i = 0; i < k; i++)
                        sum += grid[x + k - i][y - k + i];

                    s.insert(sum);
                }
            }
        }

        vector<int> ans(s.begin(), s.end());
        sort(ans.rbegin(), ans.rend());

        if (ans.size() > 3) ans.resize(3);

        return ans;
    }
};