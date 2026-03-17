class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;
        int diff1 = 0, diff2 = 0;
        int res = n;
        for (int i = 0; i < 2 * n; i++) {
            char c1 = (i % 2 == 0 ? '0' : '1');
            char c2 = (i % 2 == 0 ? '1' : '0');
            if (ss[i] != c1) diff1++;
            if (ss[i] != c2) diff2++;
            if (i >= n) {
                char prev_c1 = ((i - n) % 2 == 0 ? '0' : '1');
                char prev_c2 = ((i - n) % 2 == 0 ? '1' : '0');
                if (ss[i - n] != prev_c1) diff1--;
                if (ss[i - n] != prev_c2) diff2--;
            }
            if (i >= n - 1) {
                res = min({res, diff1, diff2});
            }
        }
        return res;
    }
};