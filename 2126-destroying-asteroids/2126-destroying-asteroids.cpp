class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int counts[100001] = {0};
        for (int ast : asteroids) {
            counts[ast]++;
        }
        long long currentMass = mass;
        for (int i = 1; i <= 100000; ++i) {
            if (counts[i] == 0) continue;
            if (currentMass < i) {
                return false;
            }
            currentMass += (long long)i * counts[i];
            if (currentMass >= 100000) {
                return true;
            }
        }
        return true;
    }
};