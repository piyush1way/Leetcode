class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited, vector<int>& low, vector<int>& disc,int& count, vector<vector<int>>& ans) {
        low[node] = disc[node] = count;
        visited[node] = 1;

        for (int j = 0; j < adj[node].size(); j++) {
            int neigh = adj[node][j];
            if (neigh == parent) {
                continue;
            } else if (visited[neigh]) {
                low[node] = min(low[node], low[neigh]);
            } else {
                count++;
                DFS(neigh, node, adj, visited, low, disc,count, ans);
                // bridge exist
                if (low[neigh] > disc[node]) {
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neigh);
                    ans.push_back(temp);
                }
                low[node] = min(low[node], low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int V,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> ans;
        int count = 0;
        vector<int> low(V);
        vector<int> disc(V);
        vector<bool> visited(V, 0);
        // int count=0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, adj, visited, low, disc,count, ans);
            }
        }
        return ans;
    }

}
;