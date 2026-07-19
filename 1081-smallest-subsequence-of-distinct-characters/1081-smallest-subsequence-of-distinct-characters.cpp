class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        string result = "";
        vector<bool> in_stack(26, false);
        for (char c : s) {
            count[c - 'a']--;
            if (in_stack[c - 'a']) continue;
            while (!result.empty() && c < result.back() && count[result.back() - 'a'] > 0) {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            in_stack[c - 'a'] = true;
        }
        return result;
    }
};