class Solution {
public:
    bool possible(long long x, long long z, long long n, long long k) {
        long long T = x * k;
        long long ones = n - z;
        if (T < z) return false;
        if ((T - z) % 2) return false;
        long long maxZero = (x % 2 ? x : x - 1);
        long long maxOne  = (x % 2 ? x - 1 : x);
        long long maxSum = z * maxZero + ones * maxOne;
        return maxSum >= T;
    }
    int minOperations(string s, int k) {
        long long n = s.size();
        long long z = 0;
        for (char c : s) if (c == '0') z++;
        if (z == 0) return 0;
        long long start = (z + k - 1) / k;
        for (long long x = start; x <= n + 5; x++) {
            if (possible(x, z, n, k)) return (int)x;
        }
        return -1;
    }
};