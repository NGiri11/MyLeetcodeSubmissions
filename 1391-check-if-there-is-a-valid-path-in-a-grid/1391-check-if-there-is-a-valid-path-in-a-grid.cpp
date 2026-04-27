class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int,int>>> dirs = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };
        auto isValid = [&](int x, int y, int px, int py) {
            for (auto &d : dirs[grid[x][y]]) {
                if (x + d.first == px && y + d.second == py)
                    return true;
            }
            return false;
        };
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        q.push({0,0});
        vis[0][0] = true;
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            if (x == m-1 && y == n-1) return true;
            for (auto &d : dirs[grid[x][y]]) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[nx][ny]) continue;
                if (isValid(nx, ny, x, y)) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
};