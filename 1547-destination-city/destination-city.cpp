class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> Indegree, Outdegree;
        for(int i = 0; i < paths.size(); i++) {
            string u = paths[i][0], v = paths[i][1];
            Outdegree[u]++;
            Indegree[v]++;
        }

        for(int i = 0; i < paths.size(); i++) {
            string v = paths[i][1];
            if(Outdegree[v] == 0) 
                return v; 
        }

        return ""; 
    }
};
