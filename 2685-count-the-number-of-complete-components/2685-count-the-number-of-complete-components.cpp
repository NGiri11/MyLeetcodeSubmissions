class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                int vertexCount = 0;
                int totalDegree = 0;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    vertexCount++;
                    totalDegree += adj[curr].size();
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                if (totalDegree == vertexCount * (vertexCount - 1)) {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }
};