class Solution {
public:
    int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minimumDistance(string word) {
        int n = word.size();
        vector<int> dp(26, 0);
        for (int i = 1; i < n; i++) {
            vector<int> newdp(26, INT_MAX);
            int curr = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            for (int j = 0; j < 26; j++) {
                newdp[j] = min(newdp[j], dp[j] + dist(prev, curr));
                newdp[prev] = min(newdp[prev], dp[j] + dist(j, curr));
            }
            dp = newdp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};