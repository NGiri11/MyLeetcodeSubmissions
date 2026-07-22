class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int initial_ones = 0;
        for (char c : s) {
            if (c == '1') initial_ones++;
        }
        vector<pair<char, int>> blocks;
        for (char c : t) {
            if (!blocks.empty() && blocks.back().first == c) {
                blocks.back().second++;
            } else {
                blocks.push_back({c, 1});
            }
        }
        int max_z1 = 0, idx1 = -1;
        int max_z2 = 0, idx2 = -1;
        for (int i = 0; i < blocks.size(); ++i) {
            if (blocks[i].first == '0') {
                int len = blocks[i].second;
                if (len > max_z1) {
                    max_z2 = max_z1;
                    idx2 = idx1;
                    max_z1 = len;
                    idx1 = i;
                } else if (len > max_z2) {
                    max_z2 = len;
                    idx2 = i;
                }
            }
        }
        int max_gain = 0;
        for (int i = 1; i < (int)blocks.size() - 1; ++i) {
            if (blocks[i].first == '1') {
                int L1 = blocks[i].second;
                int left_zero_idx = i - 1;
                int right_zero_idx = i + 1;
                int A = blocks[left_zero_idx].second;
                int B = blocks[right_zero_idx].second;
                max_gain = max(max_gain, A + B);
                int best_other_zero = 0;
                if (idx1 != left_zero_idx && idx1 != right_zero_idx) {
                    best_other_zero = max_z1;
                } else if (idx2 != left_zero_idx && idx2 != right_zero_idx) {
                    best_other_zero = max_z2;
                }
                if (best_other_zero > 0) {
                    max_gain = max(max_gain, best_other_zero - L1);
                }
            }
        }
        return initial_ones + max_gain;
    }
};