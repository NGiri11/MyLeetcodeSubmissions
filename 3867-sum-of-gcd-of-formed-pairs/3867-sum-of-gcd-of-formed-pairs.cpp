class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int currentMax = 0;
        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            prefixGcd[i] = gcd(nums[i], currentMax);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            totalSum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return totalSum;
    }
};