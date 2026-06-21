class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_c = *std::max_element(costs.begin(), costs.end());
        vector<int> freq(max_c + 1, 0);
        for (int c : costs) {
            freq[c]++;
        }
        int ans = 0;
        for (int p = 1; p <= max_c; ++p) {
            if (freq[p] == 0) continue;
            if (coins < p) break;
            int buy = min(freq[p], coins / p);
            ans += buy;
            coins -= buy * p;
        }
        return ans;
    }
};