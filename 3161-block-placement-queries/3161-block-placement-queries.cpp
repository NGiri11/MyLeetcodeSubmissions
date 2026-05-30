class Solution {
private:
    int tree[200005];
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        int M = min(50000, max_x);
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(M + 1);
        update(1, 0, M + 1, M + 1, M + 1);
        vector<bool> results;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int R = *it;
                int L = *prev(it);
                obstacles.insert(x);
                update(1, 0, M + 1, x, x - L);
                update(1, 0, M + 1, R, R - x);
            } else {
                int x = q[1];
                int sz = q[2];
                auto it = obstacles.upper_bound(x);
                int L = *prev(it);
                int max_left_gap = query(1, 0, M + 1, 0, L);
                int leftover_gap = x - L;
                results.push_back(max(max_left_gap, leftover_gap) >= sz);
            }
        }
        return results;
    }
};