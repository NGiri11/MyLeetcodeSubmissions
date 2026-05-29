class Solution {
private:
    vector<vector<int>> trie;
    vector<int> best_idx_map;
    int node_count;
    bool isBetter(int new_idx, int old_idx, const vector<string>& wordsContainer) {
        if (old_idx == -1) return true;
        int len_new = wordsContainer[new_idx].length();
        int len_old = wordsContainer[old_idx].length();
        if (len_new < len_old) return true;
        if (len_new == len_old && new_idx < old_idx) return true;
        return false;
    }
    void createNewNode() {
        trie.push_back(vector<int>(26, 0));
        best_idx_map.push_back(-1);
    }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        trie.clear();
        best_idx_map.clear();
        node_count = 0;
        createNewNode();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            const string& word = wordsContainer[i];
            int curr = 0;
            if (isBetter(i, best_idx_map[0], wordsContainer)) {
                best_idx_map[0] = i;
            }
            for (int j = word.length() - 1; j >= 0; --j) {
                int idx = word[j] - 'a';
                if (trie[curr][idx] == 0) {
                    node_count++;
                    createNewNode();
                    trie[curr][idx] = node_count;
                }
                curr = trie[curr][idx];
                if (isBetter(i, best_idx_map[curr], wordsContainer)) {
                    best_idx_map[curr] = i;
                }
            }
        }
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& query : wordsQuery) {
            int curr = 0;
            for (int j = query.length() - 1; j >= 0; --j) {
                int idx = query[j] - 'a';
                if (trie[curr][idx] != 0) {
                    curr = trie[curr][idx];
                } else {
                    break;
                }
            }
            ans.push_back(best_idx_map[curr]);
        }
        return ans;
    }
};