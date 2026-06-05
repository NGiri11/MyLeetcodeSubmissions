class Solution {
private:
    struct Result {
        long long count;
        long long waviness;
    };
    Result memo[17][11][3][2][2];
    string limitStr;
    Result dp(int idx, int prevDigit, int trend, int isLess, int isStarted) {
        if (idx == limitStr.length()) {
            return {1, 0}; 
        }
        int pKey = prevDigit + 1;
        if (memo[idx][pKey][trend][isLess][isStarted].count != -1) {
            return memo[idx][pKey][trend][isLess][isStarted];
        }
        long long totalCount = 0;
        long long totalWaviness = 0;
        int maxDigit = isLess ? 9 : (limitStr[idx] - '0');
        for (int d = 0; d <= maxDigit; d++) {
            int nextIsLess = (isLess || d < maxDigit) ? 1 : 0;
            if (!isStarted) {
                if (d == 0) {
                    Result res = dp(idx + 1, -1, 2, nextIsLess, 0);
                    totalCount += res.count;
                    totalWaviness += res.waviness;
                } else {
                    Result res = dp(idx + 1, d, 2, nextIsLess, 1);
                    totalCount += res.count;
                    totalWaviness += res.waviness;
                }
            } else {
                int wavinessEarned = 0;
                int nextTrend = 2;
                if (prevDigit != -1) {
                    if (trend == 1 && d < prevDigit) {
                        wavinessEarned = 1;
                    } else if (trend == 0 && d > prevDigit) {
                        wavinessEarned = 1;
                    }
                    if (d > prevDigit) {
                        nextTrend = 1; 
                    } else if (d < prevDigit) {
                        nextTrend = 0; 
                    } else {
                        nextTrend = 2; 
                    }
                }
                Result res = dp(idx + 1, d, nextTrend, nextIsLess, 1);
                totalCount += res.count;
                totalWaviness += res.waviness + (wavinessEarned * res.count);
            }
        }
        return memo[idx][pKey][trend][isLess][isStarted] = {totalCount, totalWaviness};
    }
    long long solve(long long maxLimit) {
        if (maxLimit < 100) return 0; 
        limitStr = to_string(maxLimit);
        memset(memo, -1, sizeof(memo));
        return dp(0, -1, 2, 0, 0).waviness;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};