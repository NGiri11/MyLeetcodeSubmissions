class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dir = 0;
        int x = 0, y = 0;
        int maxDist = 0;
        unordered_set<long long> obsSet;
        for (auto& o : obstacles) {
            long long key = ((long long)o[0] + 30000) * 60001LL + (o[1] + 30000);
            obsSet.insert(key);
        }
        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;
                    long long key = ((long long)nx + 30000) * 60001LL + (ny + 30000);
                    if (obsSet.find(key) != obsSet.end()) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};