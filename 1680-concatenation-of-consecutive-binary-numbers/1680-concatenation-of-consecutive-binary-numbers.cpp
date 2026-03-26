class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        for (int i = 1; i <= n; i++) {
            int length = 32 - __builtin_clz(i); 
            result = ((result << length) + i) % MOD;
        }
        return (int)result;
    }
};