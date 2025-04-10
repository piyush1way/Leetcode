class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<int>Indegree(v,0);
        queue<int>q;
        vector<vector<int>> adj(v);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int pre = prerequisites[i][1];
            adj[pre].push_back(u);  
            Indegree[u]++;
        }
        for(int i =0;i<v;i++){
            if(!Indegree[i]){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int j =0;j<adj[node].size();j++){
                int neigh = adj[node][j];
                Indegree[neigh]--;
                if(!Indegree[neigh]){
                    q.push(neigh);
                }
            }
        }
        if(ans.size()!=v){
            return {};
        }
        return ans;
    }
};