class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> r(n);
        for (int i = 0; i < n; i++) r[i] = {robots[i], distance[i]};
        sort(r.begin(), r.end());

        for (int i = 0; i < n; i++) {
            robots[i] = r[i].first;
            distance[i] = r[i].second;
        }

        auto countWalls = [&](long long l, long long r) {
            if (l > r) return 0;
            return (int)(upper_bound(walls.begin(), walls.end(), r) -
                         lower_bound(walls.begin(), walls.end(), l));
        };

        vector<pair<long long,long long>> L(n), R(n);
        vector<int> leftCnt(n), rightCnt(n);

        for (int i = 0; i < n; i++) {
            long long l = robots[i] - distance[i];
            long long rgt = robots[i] + distance[i];

            if (i > 0) l = max(l, (long long)robots[i-1] + 1);
            if (i < n-1) rgt = min(rgt, (long long)robots[i+1] - 1);

            L[i] = {l, robots[i]};
            R[i] = {robots[i], rgt};

            leftCnt[i] = countWalls(L[i].first, L[i].second);
            rightCnt[i] = countWalls(R[i].first, R[i].second);
        }

        vector<int> overlap(n, 0);
        for (int i = 1; i < n; i++) {
            long long l = max(R[i-1].first, L[i].first);
            long long rgt = min(R[i-1].second, L[i].second);
            overlap[i] = countWalls(l, rgt);
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = leftCnt[0];
        dp[0][1] = rightCnt[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(
                dp[i-1][0] + leftCnt[i],
                dp[i-1][1] + leftCnt[i] - overlap[i]
            );

            dp[i][1] = max(
                dp[i-1][0] + rightCnt[i],
                dp[i-1][1] + rightCnt[i]
            );
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};