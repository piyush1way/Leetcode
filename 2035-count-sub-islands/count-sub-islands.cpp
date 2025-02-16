class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool check = true;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    if (grid1[i][j] == 0) {
                        continue;
                    }
                    check = true;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if (grid1[x][y] == 0) {
                            check = false;
                        }

                        for (int k = 0; k < 4; k++) {
                            int ni = x + row[k];
                            int nj = y + col[k];

                            if (valid(ni, nj, n, m) && grid2[ni][nj] == 1 &&
                                !visited[ni][nj]) {
                                q.push({ni, nj});
                                visited[ni][nj] = true;
                            }
                        }
                    }
                    if (check == true) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};