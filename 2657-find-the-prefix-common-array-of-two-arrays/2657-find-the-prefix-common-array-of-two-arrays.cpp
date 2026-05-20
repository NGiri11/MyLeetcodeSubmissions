class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        vector<int> seen_count(n + 1, 0);
        int current_common = 0;
        for (int i = 0; i < n; ++i) {
            seen_count[A[i]]++;
            if (seen_count[A[i]] == 2) {
                current_common++;
            }
            seen_count[B[i]]++;
            if (seen_count[B[i]] == 2) {
                current_common++;
            }
            C[i] = current_common;
        }
        return C;
    }
};