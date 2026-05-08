class Solution {
public:
    static const int MAXV = 1000000;
    static vector<int> spf;
    static void buildSieve() {
        if (!spf.empty()) return;
        spf.resize(MAXV + 1);
        for (int i = 0; i <= MAXV; i++)
            spf[i] = i;
        for (long long i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        buildSieve();
        int n = nums.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> divs;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                divs[p].push_back(i);
                while (x % p == 0)
                    x /= p;
            }
        }
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        unordered_set<int> usedPrime;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int steps = dist[i];
            if (i == n - 1)
                return steps;
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }
            int val = nums[i];
            if (val >= 2 && spf[val] == val &&
                !usedPrime.count(val)) {
                usedPrime.insert(val);
                auto &vec = divs[val];
                for (int idx : vec) {
                    if (dist[idx] == -1) {
                        dist[idx] = steps + 1;
                        q.push(idx);
                    }
                }
                vec.clear();
            }
        }
        return -1;
    }
};
vector<int> Solution::spf;