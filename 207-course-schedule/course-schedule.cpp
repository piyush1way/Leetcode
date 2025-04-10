class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
              vector<int>& ans, bool &valid,vector<bool>& pathVisited) {
                if(!valid){
                    return;
                }
        visited[node] = 1;
        pathVisited[node]=1;
        for (int j = 0; j < adj[node].size(); j++) {
            int neigh = adj[node][j];
            if(pathVisited[neigh]){
                valid=false;
                return;
            }
            if (!visited[neigh]) {
                dfs(neigh, adj, visited, ans,valid,pathVisited);
            }
        }
        pathVisited[node]=0;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<bool> pathVisited(numCourses, 0);
        // dfslogical sort
        vector<int> ans;
        vector<bool> visited(numCourses, 0);
        bool valid=true;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && valid) {
                dfs(i, adj, visited, ans,valid,pathVisited);
            }
        }

        return valid;
    }
};