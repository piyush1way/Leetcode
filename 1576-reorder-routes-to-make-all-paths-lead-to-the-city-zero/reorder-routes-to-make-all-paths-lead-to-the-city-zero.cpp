class Solution {
public:

    void DFS(int node, int &changes, vector<vector<int>>& adj,vector<int>&visited,set<pair<int,int>>&st){
        visited[node]=1;

        //explore neighbours
        for(int j =0;j<adj[node].size();j++){
            int neigh = adj[node][j];
            if(visited[neigh]){
                continue;
            }
            if(st.count({neigh,node})==0){
                changes++;
            }
            if(!visited[neigh]){
                DFS(neigh,changes,adj,visited,st);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int changes =0;
        // treat graph as undirected;
        vector<vector<int>> adj(n);
        set<pair<int,int>>st;
        for(int i =0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            st.insert({u,v});
        }
        vector<int>visited(n,0);
        visited[0]=1;
        DFS(0,changes,adj,visited,st);
        return changes;
    }
};