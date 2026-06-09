class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int global_max = nums[0];
        int global_min = nums[0];
        for (int num : nums) {
            if (num > global_max) global_max = num;
            if (num < global_min) global_min = num;
        }
        return (long long)(global_max - global_min) * k;
    }
};