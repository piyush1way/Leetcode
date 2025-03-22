class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < m && j < n && m!=0 && n!=0) {
            if (nums1[i] >= nums2[j]) {
                ans.push_back(nums2[j]);
                j++;
            } else if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
        }
        while (i < m && m!=0) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n && n!=0) {
            ans.push_back(nums2[j]);
            j++;
        }
        nums1=ans;
    }
};