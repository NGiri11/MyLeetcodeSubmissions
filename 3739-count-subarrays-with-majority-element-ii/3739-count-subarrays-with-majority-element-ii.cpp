class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 1;
        vector<int> count_at_sum(2 * n + 2, 0);
        int curr_sum = 0;
        count_at_sum[curr_sum + offset] = 1;
        long long ans = 0;
        long long smaller_count = 0;
        for (int num : nums) {
            if (num == target) {
                smaller_count += count_at_sum[curr_sum + offset];
                curr_sum++;
            } else {
                curr_sum--;
                smaller_count -= count_at_sum[curr_sum + offset];
            }
            ans += smaller_count;
            count_at_sum[curr_sum + offset]++;
        }
        return ans;
    }
};