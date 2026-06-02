class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minFinishTime = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int landEnd = landStartTime[i] + landDuration[i];
                int waterStart = max(landEnd, waterStartTime[j]);
                int finishTime1 = waterStart + waterDuration[j];
                int waterEnd = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterEnd, landStartTime[i]);
                int finishTime2 = landStart + landDuration[i];
                minFinishTime = min({minFinishTime, finishTime1, finishTime2});
            }
        }
        return minFinishTime;
    }
};