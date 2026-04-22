class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        auto hammingDistance = [](const string& a, const string& b) {
            int diff = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) diff++;
                if (diff > 2) return diff;
            }
            return diff;
        };
        for (auto& q : queries) {
            for (auto& d : dictionary) {
                if (hammingDistance(q, d) <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};
