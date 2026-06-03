class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minFL = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minFL = min(minFL, landStartTime[i] + landDuration[i]);
        }
        int minFW = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minFW = min(minFW, waterStartTime[j] + waterDuration[j]);
        }
        int ans1 = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int total = max(minFL, waterStartTime[j]) + waterDuration[j];
            ans1 = min(ans1, total);
        }
        int ans2 = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int total = max(minFW, landStartTime[i]) + landDuration[i];
            ans2 = min(ans2, total);
        }
        return min(ans1, ans2);
    }
};