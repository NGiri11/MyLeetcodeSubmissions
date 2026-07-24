class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pair_xors(2048, false);
        vector<bool> triplet_xors(2048, false);
        for (int x : nums) {
            triplet_xors[x] = true;
        }
        for (int i = 0; i < n; ++i) {
            int curr = nums[i];
            for (int p = 0; p < 2048; ++p) {
                if (pair_xors[p]) {
                    triplet_xors[p ^ curr] = true;
                }
            }
            for (int j = 0; j < i; ++j) {
                pair_xors[nums[j] ^ curr] = true;
            }
        }
        int count = 0;
        for (bool present : triplet_xors) {
            if (present) count++;
        }
        return count;
    }
};