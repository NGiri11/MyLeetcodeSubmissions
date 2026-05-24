class Solution {
private:
    vector<int> memo;
    int dfs(int i, const vector<int>& arr, int d) {
        if (memo[i] != 0) return memo[i];
        int n = arr.size();
        int maxResult = 1;
        for (int x = 1; x <= d && i + x < n; ++x) {
            if (arr[i + x] >= arr[i]) break; 
            maxResult = max(maxResult, 1 + dfs(i + x, arr, d));
        }
        for (int x = 1; x <= d && i - x >= 0; ++x) {
            if (arr[i - x] >= arr[i]) break; 
            maxResult = max(maxResult, 1 + dfs(i - x, arr, d));
        }
        return memo[i] = maxResult;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memo.assign(n, 0); 
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, dfs(i, arr, d));
        }
        return maxVal;
    }
};