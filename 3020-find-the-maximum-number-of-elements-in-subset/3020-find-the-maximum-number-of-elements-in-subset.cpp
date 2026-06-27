class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) count[num]++;
        int ans = (count[1] % 2 == 0) ? count[1] - 1 : count[1];
        ans = max(ans, 1);
        for (auto& [x, freq] : count) {
            if (x == 1) continue;
            int current_len = 0;
            long long curr = x;
            while (count.count(curr) && count[curr] >= 2) {
                current_len += 2;
                if (curr > 31622) {
                    curr = 1e18;
                    break;
                }
                curr = curr * curr;  
            }
            if (count.count(curr) && count[curr] >= 1) current_len += 1;
            else current_len -= 1;
            ans = max(ans, current_len);
        }
        return ans;
    }
};