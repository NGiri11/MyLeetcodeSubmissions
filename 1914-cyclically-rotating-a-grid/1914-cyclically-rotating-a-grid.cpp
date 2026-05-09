class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;
        for (int layer = 0; layer < numLayers; ++layer) {
            int rMin = layer, rMax = m - 1 - layer;
            int cMin = layer, cMax = n - 1 - layer;
            vector<int> elements;
            for (int j = cMin; j < cMax; ++j) elements.push_back(grid[rMin][j]);
            for (int i = rMin; i < rMax; ++i) elements.push_back(grid[i][cMax]);
            for (int j = cMax; j > cMin; --j) elements.push_back(grid[rMax][j]);
            for (int i = rMax; i > rMin; --i) elements.push_back(grid[i][cMin]);
            int size = elements.size();
            int effectiveK = k % size;
            int index = effectiveK;
            for (int j = cMin; j < cMax; ++j) grid[rMin][j] = elements[index++ % size];
            for (int i = rMin; i < rMax; ++i) grid[i][cMax] = elements[index++ % size];
            for (int j = cMax; j > cMin; --j) grid[rMax][j] = elements[index++ % size];
            for (int i = rMax; i > rMin; --i) grid[i][cMin] = elements[index++ % size];
        }
        return grid;
    }
};