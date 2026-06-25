class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSubarrays = 0;
        for (int i = 0; i < n; ++i) {
            int balance = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    balance += 1;
                } else {
                    balance -= 1;
                }
                if (balance > 0) {
                    totalSubarrays++;
                }
            }
        }
        return totalSubarrays;
    }
};