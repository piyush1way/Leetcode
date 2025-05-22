class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int n = rooms.size();
        vector<int> visited(n, 0);
        visited[0] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int k = 0; k < rooms[node].size(); k++) {
                int neighbor = rooms[node][k];
                if (neighbor != node && !visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};