class Solution {
public:
    void DFS(int node, vector<int>& visited, vector<vector<int>>& adj,
             vector<int>& component) {
        visited[node] = 1;
        component.push_back(node);
        // explore neighbours
        for (int j = 0; j < adj[node].size(); j++) {
            int neighbour = adj[node][j];
            if (!visited[neighbour]) {
                DFS(neighbour, visited, adj, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        int m = edges.size();
        vector<int> visited(n, 0);
        // vector<int> component;
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                DFS(i, visited, adj, component);

                // Check if the component forms a complete subgraph
                int size = component.size();
                bool isComplete = true;
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete)
                    count++;
            }
        }
        return count;
    }
};