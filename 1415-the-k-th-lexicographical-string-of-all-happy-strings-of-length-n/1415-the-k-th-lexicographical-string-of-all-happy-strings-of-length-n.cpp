class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";
        string result;
        char prev = '\0';
        for (int i = 0; i < n; i++) {
            int blockSize = 1 << (n - i - 1);
            for (char c : {'a', 'b', 'c'}) {
                if (c == prev) continue;
                if (k > blockSize) {
                    k -= blockSize;
                } else {
                    result.push_back(c);
                    prev = c;
                    break;
                }
            }
        }
        return result;
    }
};