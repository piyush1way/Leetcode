class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                count++;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neigh : adj[node]) {
                        if (!visited[neigh]) {
                            q.push(neigh);
                            visited[neigh] = true;
                        }
                    }
                }
            }
        }

        return count;
    }
};