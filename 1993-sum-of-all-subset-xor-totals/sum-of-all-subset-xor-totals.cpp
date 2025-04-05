class Solution {
public:
    int find(int i, int currXor, int n, vector<int>& nums) {
        if (i == n) {
            return currXor;
        }
        int exclude = find(i + 1, currXor, n, nums);
        int include = find(i + 1, currXor ^ nums[i], n, nums);
        return exclude + include;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return find(0, 0, n, nums);
    }
};
