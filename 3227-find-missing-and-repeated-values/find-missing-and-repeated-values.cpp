class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>ans;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                int curr = abs(grid[i][j]);
                int row = (curr-1)/n;
                int col = (curr-1)%n;
                if(grid[row][col]<0){
                    ans.push_back(abs(grid[i][j]));
                }
                else{
                    grid[row][col]=grid[row][col]*-1;
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]>0){
                    ans.push_back(i*n+j+1);
                    break;
                }
            }
        }
        return ans;
    }
};