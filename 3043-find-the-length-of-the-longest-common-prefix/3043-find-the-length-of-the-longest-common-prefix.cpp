class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }
        int longest_len = 0;
        for (int val : arr2) {
            while (val > 0) {
                int current_len = 0;
                int temp = val;
                while (temp > 0) {
                    current_len++;
                    temp /= 10;
                }
                if (current_len <= longest_len) {
                    break;
                }
                if (prefixes.count(val)) {
                    longest_len = max(longest_len, current_len);
                    break;
                }
                val /= 10;
            }
        }
        return longest_len;
    }
};