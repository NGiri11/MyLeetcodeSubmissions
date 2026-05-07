class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i + 1], nums[i]);
        }
        vector<int> ans(n);
        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (pref[i] <= suff[i + 1]) {
                int mx = pref[i];
                for (int j = start; j <= i; j++) {
                    ans[j] = mx;
                }
                start = i + 1;
            }
        }
        int mx = nums[start];
        for (int j = start; j < n; j++) {
            mx = max(mx, nums[j]);
        }
        for (int j = start; j < n; j++) {
            ans[j] = mx;
        }
        return ans;
    }
};