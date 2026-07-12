class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> uniqueSortedElements(arr.begin(), arr.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : uniqueSortedElements) {
            rankMap[num] = rank++;
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }
        return arr;
    }
};