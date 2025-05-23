class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long total_cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q2;
        int i = 0;
        int j = n - 1;
        while (q1.size() < candidates && i <= j) {
            q1.push({costs[i], i});
            i++;
        }

        while (q2.size() < candidates && j >= i) {
            q2.push({costs[j], j});
            j--;
        }
        while (k--) {
            int ltop = INT_MAX;
            if (!q1.empty()) {
                ltop = q1.top().first;
            }
            int rtop = INT_MAX;
            if (!q2.empty()) {
                rtop = q2.top().first;
            }
            if (q1.empty() && q2.empty()) {
                break;
            }
            if (ltop > rtop) {
                total_cost += rtop;
                q2.pop();
                if (j >= i) {
                    q2.push({costs[j], j});
                    j--;
                }
            } else {
                total_cost += ltop;
                q1.pop();
                if (i <= j) {
                    q1.push({costs[i], i});
                    i++;
                }
            }
        }
        return total_cost;
    }
};