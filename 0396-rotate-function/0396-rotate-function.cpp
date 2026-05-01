class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long f0 = 0;
        for (long long i = 0; i < n; i++) {
            sum += nums[i];
            f0 += i * nums[i];
        }
        long long maxF = f0;
        long long currentF = f0;
        for (long long k = 1; k < n; k++) {
            currentF = currentF + sum - n * nums[n - k];
            maxF = max(maxF, currentF);
        }
        return maxF;
    }
};