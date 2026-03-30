class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even_counts(26, 0);
        vector<int> odd_counts(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even_counts[s1[i] - 'a']++;
                even_counts[s2[i] - 'a']--;
            } else {
                odd_counts[s1[i] - 'a']++;
                odd_counts[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (even_counts[i] != 0 || odd_counts[i] != 0) {
                return false;
            }
        }
        return true;
    }
};