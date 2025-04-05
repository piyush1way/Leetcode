class Solution {
public:
    void find(int i, vector<vector<int>> &ans, vector<int> temp, int n,
              vector<int>& nums) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        // exclude
        find(i + 1, ans, temp, n, nums);
        // include
        temp.push_back(nums[i]);
        find(i + 1, ans, temp, n, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        find(0, ans, temp, n, nums);
        return ans;
    }
};