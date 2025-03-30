class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.push_back(grid[i][j]);
            }
        }
        // int m = ans.size();

        sort(ans.begin(), ans.end());
        // check whether it satisfies condition
        int rem = ans[0] % x;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] % x != rem) {
                return -1;
            }
        }
        int mid = ans.size() / 2;
        int operations = 0;
        for (int i = 0; i < ans.size(); i++) {
            operations += (abs(ans[mid] - ans[i])) / x;
        }
        return operations;
    }
};