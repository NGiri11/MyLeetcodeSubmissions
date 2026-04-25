class Solution {
public:
    long long perimeter;

    long long getPos(int x, int y, int side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }

    bool can(vector<long long>& a, int k, long long d) {
        int n = a.size() / 2;

        vector<int> next(2 * n);

        // 🔹 Build next pointer using two pointers
        int j = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (j < 2 * n && a[j] - a[i] < d) j++;
            next[i] = j;
        }

        // 🔹 Try each start
        for (int i = 0; i < n; i++) {
            int curr = i;
            int count = 1;

            for (int step = 1; step < k; step++) {
                curr = next[curr];
                if (curr >= i + n) break;
                count++;
            }

            if (count >= k) {
                long long first = a[i];
                long long last = a[curr];

                if (last - first <= perimeter - d)
                    return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        perimeter = 4LL * side;

        vector<long long> pos;
        for (auto &p : points)
            pos.push_back(getPos(p[0], p[1], side));

        sort(pos.begin(), pos.end());

        int m = pos.size();
        for (int i = 0; i < m; i++)
            pos.push_back(pos[i] + perimeter);

        long long lo = 0, hi = perimeter / k, ans = 0;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            if (can(pos, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};