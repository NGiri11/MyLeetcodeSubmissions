class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int totalCost = 0;
        int n = cost.size();
        for (int i = 0; i < n; i++) {
            totalCost += cost[i];
            i++; 
            if (i < n) {
                totalCost += cost[i];
                i++;
            }
        }
        return totalCost;
    }
};