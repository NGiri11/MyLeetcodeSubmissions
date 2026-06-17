class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths;
        lengths.reserve(n);
        long long currentLen = 0;
        int limitIndex = n;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') {
                currentLen++;
            } else if (ch == '*') {
                currentLen = max(0LL, currentLen - 1);
            } else if (ch == '#') {
                currentLen *= 2;
            } else if (ch == '%') {
            }
            lengths.push_back(currentLen);
            if (currentLen > 1000000000000000LL) {
                limitIndex = i + 1;
                break;
            }
        }
        if (k < 0 || k >= currentLen) {
            return '.';
        }
        for (int i = limitIndex - 1; i >= 0; i--) {
            char ch = s[i];
            long long prevLen = (i == 0) ? 0 : lengths[i - 1];
            if (ch >= 'a' && ch <= 'z') {
                if (k == prevLen) {
                    return ch;
                }
            } else if (ch == '#') {
                if (k >= prevLen) {
                    k -= prevLen;
                }
            } else if (ch == '%') {
                k = currentLen - 1 - k;
            } else if (ch == '*') {
            }
            currentLen = prevLen;
        }
        return '.';
    }
};