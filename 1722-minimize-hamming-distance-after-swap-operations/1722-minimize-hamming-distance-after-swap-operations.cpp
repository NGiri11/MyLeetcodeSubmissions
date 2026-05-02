class Solution {
private:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (const auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
        unordered_map<int, unordered_map<int, int>> componentCounts;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            componentCounts[root][source[i]]++;
        }
        int hammingDistance = 0;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            int targetVal = target[i];
            if (componentCounts[root][targetVal] > 0) {
                componentCounts[root][targetVal]--;
            } else {
                hammingDistance++;
            }
        }
        return hammingDistance;
    }
};