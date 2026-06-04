#include <string>

class Solution {
private:
    int getWaviness(int n) {
        string s=to_string(n);
        if (s.length() < 3) return 0;
        int waviness = 0;
        for (size_t i = 1; i < s.length() - 1; ++i) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) || 
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                waviness++;
            }
        }
        return waviness;
    }
public:
    int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        for (int i = num1; i <= num2; ++i) {
            totalSum += getWaviness(i);
        }
        return totalSum;
    }
};