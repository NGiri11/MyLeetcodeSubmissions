class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = '0';
        for (char c : n) {
            if (c > maxDigit) maxDigit = c;
        }
        return maxDigit - '0';
    }
};