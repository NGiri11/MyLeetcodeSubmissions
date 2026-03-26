class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k;
        vector<bool> seen(need, false);
        int allOnes = need - 1;
        int hashVal = 0;
        for (int i = 0; i < s.size(); i++) {
            hashVal = ((hashVal << 1) & allOnes) | (s[i] - '0');
            if (i >= k - 1) {
                if (!seen[hashVal]) {
                    seen[hashVal] = true;
                    need--;
                    if (need == 0) return true;
                }
            }
        }
        return need == 0;
    }
};