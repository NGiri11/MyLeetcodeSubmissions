class Fancy {
    static const int MOD = 1e9 + 7;
    vector<long long> seq;
    vector<long long> multHistory;
    vector<long long> addHistory;
    long long mult = 1, add = 0;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        seq.push_back(((val - add + MOD) % MOD * modPow(mult, MOD - 2)) % MOD);
        multHistory.push_back(mult);
        addHistory.push_back(add);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mult = (mult * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        long long val = seq[idx];
        long long m = multHistory[idx];
        long long a = addHistory[idx];
        return (val * mult + add) % MOD;
    }
};