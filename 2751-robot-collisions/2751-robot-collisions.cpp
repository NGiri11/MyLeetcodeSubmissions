class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int,int,char,int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end());
        stack<int> st;
        for (int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];
            if (dir == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && health > 0) {
                    auto &[posR, healthR, dirR, idxR] = robots[st.top()];
                    if (healthR < health) {
                        st.pop();
                        health -= 1;
                        healthR = 0;
                    } 
                    else if (healthR == health) {
                        st.pop();
                        healthR = 0;
                        health = 0;
                        break;
                    } 
                    else {
                        healthR -= 1;
                        health = 0;
                        break;
                    }
                }
            }
        }
        vector<pair<int,int>> survivors;
        for (auto &[pos, health, dir, idx] : robots) {
            if (health > 0) {
                survivors.push_back({idx, health});
            }
        }
        sort(survivors.begin(), survivors.end());
        vector<int> result;
        for (auto &p : survivors) {
            result.push_back(p.second);
        }
        return result;
    }
};