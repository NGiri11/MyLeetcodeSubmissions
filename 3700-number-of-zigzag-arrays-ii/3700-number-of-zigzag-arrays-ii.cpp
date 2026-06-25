class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    vector<vector<long long>> power(vector<vector<long long>> T, long long p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, T, size);
            T = multiply(T, T, size);
            p >>= 1;
        }
        return res;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;
        vector<vector<long long>> T(size, vector<long long>(size, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                T[m + j][i] = 1; 
            }
            for (int j = 0; j < i; ++j) {
                T[j][m + i] = 1;
            }
        }
        vector<vector<long long>> Tn = power(T, n - 1, size);
        long long totalArrays = 0;
        for (int start = 0; start < m; ++start) {
            long long current_ways = 0;
            for (int final_state = 0; final_state < size; ++final_state) {
                current_ways = (current_ways + Tn[final_state][start]) % MOD;
                current_ways = (current_ways + Tn[final_state][m + start]) % MOD;
            }
            totalArrays = (totalArrays + current_ways) % MOD;
        }
        return totalArrays;
    }
};