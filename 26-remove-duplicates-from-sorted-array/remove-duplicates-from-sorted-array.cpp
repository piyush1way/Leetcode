class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while (j < n) {
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            if (j < n) {
                nums[i + 1] = nums[j];
                i++;
                j++;
            }
        }
        return i + 1;
    }
};