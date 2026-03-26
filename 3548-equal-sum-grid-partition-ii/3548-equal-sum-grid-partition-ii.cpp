class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        for (auto &row : grid)
            for (int x : row)
                total += x;

        unordered_map<int,int> top, bottom;

        // Fill bottom map
        for (auto &row : grid)
            for (int x : row)
                bottom[x]++;

        long long topSum = 0;

        // ---------- HORIZONTAL CUT ----------
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                top[v]++;
                if (--bottom[v] == 0) bottom.erase(v);
                topSum += v;
            }

            long long bottomSum = total - topSum;

            if (check(grid, topSum, bottomSum, top, bottom,
                      0, i, 0, n - 1,         // top part
                      i + 1, m - 1, 0, n - 1 // bottom part
                     )) return true;
        }

        // Reset maps
        top.clear(); bottom.clear();
        for (auto &row : grid)
            for (int x : row)
                bottom[x]++;

        long long leftSum = 0;

        // ---------- VERTICAL CUT ----------
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int v = grid[i][j];
                top[v]++;
                if (--bottom[v] == 0) bottom.erase(v);
                leftSum += v;
            }

            long long rightSum = total - leftSum;

            if (check(grid, leftSum, rightSum, top, bottom,
                      0, m - 1, 0, j,         // left part
                      0, m - 1, j + 1, n - 1 // right part
                     )) return true;
        }

        return false;
    }

private:

    bool validRemoval(long long diff,
                      unordered_map<int,int>& part,
                      int r1, int r2, int c1, int c2,
                      vector<vector<int>>& grid) {

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        // ❗ must match exactly one cell value
        if (diff <= 0 || diff > 100000) return false;

        if (!part.count((int)diff)) return false;

        // ❗ cannot remove if only one cell
        if (rows * cols == 1) return false;

        // 2D → always connected
        if (rows > 1 && cols > 1) return true;

        // 1D row → only ends
        if (rows == 1) {
            return (grid[r1][c1] == diff ||
                    grid[r1][c2] == diff);
        }

        // 1D col → only ends
        if (cols == 1) {
            return (grid[r1][c1] == diff ||
                    grid[r2][c1] == diff);
        }

        return false;
    }

    bool check(vector<vector<int>>& grid,
               long long sumA, long long sumB,
               unordered_map<int,int>& A,
               unordered_map<int,int>& B,
               int r1A, int r2A, int c1A, int c2A,
               int r1B, int r2B, int c1B, int c2B) {

        if (sumA == sumB) return true;

        if (sumA < sumB) {
            long long diff = sumB - sumA;
            return validRemoval(diff, B, r1B, r2B, c1B, c2B, grid);
        } else {
            long long diff = sumA - sumB;
            return validRemoval(diff, A, r1A, r2A, c1A, c2A, grid);
        }
    }
};