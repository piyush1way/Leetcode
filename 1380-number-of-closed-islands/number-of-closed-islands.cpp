class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int n,m;
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j]=1;
        // visited[i][j] = true;
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];
                if (valid(ni, nj, n, m) && grid[ni][nj] == 0) {
                    grid[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        // vector<vector<int>> visited(n, vector<int>(m, false));

        // make boundary 0s as visited
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0)
                bfs(grid, i, 0);
            if (grid[i][m - 1] == 0)
                bfs(grid, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0)
                bfs(grid, 0, j);
            if (grid[n - 1][j] == 0)
                bfs(grid, n - 1, j);
        }
        // cnt
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
};