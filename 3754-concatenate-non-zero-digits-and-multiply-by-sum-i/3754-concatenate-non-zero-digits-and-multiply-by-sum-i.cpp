class Solution {
public:
    long long sumAndMultiply(int n) {
        long long p = 1;
        long long x = 0;
        long long s = 0;
        while (n > 0) {
            int v = n % 10;
            if (v != 0) {
                s += v;
                x += p * v;
                p *= 10;
            }
            n /= 10;
        }
        return x * s;
    }
};