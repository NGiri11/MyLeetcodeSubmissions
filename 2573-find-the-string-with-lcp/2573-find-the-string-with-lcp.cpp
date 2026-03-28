class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }
        vector<int> group(n, -1);
        char cur = 'a';
        for (int i = 0; i < n; i++) {
            if (group[i] != -1) continue;
            if (cur > 'z') return "";
            group[i] = cur;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    group[j] = cur;
                }
            }
            cur++;
        }
        string word(n, 'a');
        for (int i = 0; i < n; i++) {
            word[i] = group[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i + 1 < n && j + 1 < n)
                        dp[i][j] = dp[i + 1][j + 1] + 1;
                    else
                        dp[i][j] = 1;
                }
            }
        }
        if (dp != lcp) return "";
        return word;
    }
};