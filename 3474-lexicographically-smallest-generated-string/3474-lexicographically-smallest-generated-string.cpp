class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        vector<char> word(len, '?');
        vector<bool> locked(len, false); // 🔥 track T-forced positions

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        locked[i + j] = true; // mark locked
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // Step 3: Fix 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;

                    // 🔥 change from rightmost but avoid locked
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (locked[pos]) continue; // ❗ skip T-forced

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                word[pos] = c;
                                changed = true;
                                break;
                            }
                        }

                        if (changed) break;
                    }

                    if (!changed) return "";
                }
            }
        }

        return string(word.begin(), word.end());
    }
};