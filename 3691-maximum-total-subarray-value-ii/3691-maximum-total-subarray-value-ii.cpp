class Solution {
private:
    struct Element {
        long long value;
        int l;
        int r;
        bool operator<(const Element& other) const {
            return value < other.value;
        }
    };
    class SparseTable {
    private:
        vector<vector<int>> maxTable;
        vector<vector<int>> minTable;
        vector<int> lg;
    public:
        SparseTable(const vector<int>& nums) {
            int n = nums.size();
            lg.assign(n + 1, 0);
            for (int i = 2; i <= n; i++) {
                lg[i] = lg[i / 2] + 1;
            }
            int maxLog = lg[n] + 1;
            maxTable.assign(n, vector<int>(maxLog, 0));
            minTable.assign(n, vector<int>(maxLog, 0));
            for (int i = 0; i < n; i++) {
                maxTable[i][0] = nums[i];
                minTable[i][0] = nums[i];
            }
            for (int j = 1; j < maxLog; j++) {
                for (int i = 0; i <= n - (1 << j); i++) {
                    maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
                    minTable[i][j] = min(minTable[i][j - 1], minTable[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
        int queryMax(int l, int r) {
            int k = lg[r - l + 1];
            return max(maxTable[l][k], maxTable[r - (1 << k) + 1][k]);
        }
        int queryMin(int l, int r) {
            int k = lg[r - l + 1];
            return min(minTable[l][k], minTable[r - (1 << k) + 1][k]);
        }
        long long subarrayValue(int l, int r) {
            return (long long)queryMax(l, r) - queryMin(l, r);
        }
    };
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);
        priority_queue<Element> pq;
        for (int l = 0; l < n; l++) {
            long long val = st.subarrayValue(l, n - 1);
            pq.push({val, l, n - 1});
        }
        long long totalValue = 0;
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            Element curr = pq.top();
            pq.pop();
            totalValue += curr.value;
            if (curr.r > curr.l) {
                long long nextVal = st.subarrayValue(curr.l, curr.r - 1);
                pq.push({nextVal, curr.l, curr.r - 1});
            }
        }
        return totalValue;
    }
};