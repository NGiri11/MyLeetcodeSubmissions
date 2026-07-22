#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable() = default;
    SparseTable(const vector<int>& nums) : n(nums.size()) {
        if (n == 0) return;
        int max_log = 32 - __builtin_clz(n);
        st.assign(max_log, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            st[0][j] = nums[j];
        }
        for (int i = 1; i < max_log; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        int i = 31 - __builtin_clz(r - l + 1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    int n = 0;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n, -1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
                zeroGroupIndex[i] = zeroGroups.size() - 1;
            } else {
                zeroGroupIndex[i] = zeroGroups.empty() ? -1 : zeroGroups.size() - 1;
            }
        }

        int m = zeroGroups.size();
        vector<int> adjSums(max(0, m - 1), 0);
        for (int i = 0; i < m - 1; ++i) {
            adjSums[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        }
        
        SparseTable st(adjSums);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int activeSections = totalOnes;

            if (m == 0) {
                ans.push_back(activeSections);
                continue;
            }

            int left = (s[l] == '0') ? (zeroGroups[zeroGroupIndex[l]].start + zeroGroups[zeroGroupIndex[l]].length - l) : 0;
            int right = (s[r] == '0') ? (r - zeroGroups[zeroGroupIndex[r]].start + 1) : 0;

            // Case 1: Merge two boundary zero groups directly
            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
                activeSections = max(activeSections, totalOnes + left + right);
            }

            // Case 2: Merge fully internal zero groups
            int startAdj = (s[l] == '0') ? zeroGroupIndex[l] + 1 : zeroGroupIndex[l] + 1;
            int endAdj = (s[r] == '0') ? zeroGroupIndex[r] - 2 : zeroGroupIndex[r] - 1;
            if (startAdj <= endAdj && startAdj >= 0 && endAdj < m - 1) {
                activeSections = max(activeSections, totalOnes + st.query(startAdj, endAdj));
            }

            // Case 3: Truncated left + fully internal right
            int limitR = (s[r] == '0') ? zeroGroupIndex[r] - 1 : zeroGroupIndex[r];
            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= limitR) {
                activeSections = max(activeSections, totalOnes + left + zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            // Case 4: Fully internal left + truncated right (fixed typo zeroGroupIndex[1] -> zeroGroupIndex[l])
            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {
                activeSections = max(activeSections, totalOnes + right + zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(activeSections);
        }

        return ans;
    }
};