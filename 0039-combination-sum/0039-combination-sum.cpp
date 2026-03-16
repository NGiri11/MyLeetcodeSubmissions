class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, vector<int>& path, int start) {
        if(target == 0) {
            res.push_back(path);
            return;
        }
        if(target < 0) return;
        for(int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], path, i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(candidates, target, path, 0);
        return res;
    }
};