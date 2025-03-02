class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int p = 0;
        int q = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        while(p<n && q<m){
            if(nums1[p][0]==nums2[q][0]){
                int x = nums1[p][1] + nums2[q][1];
                vector<int>temp;
                temp.push_back(nums1[p][0]);
                temp.push_back(x);
                ans.push_back(temp);
                p++;q++;
            }
            else if(nums1[p][0]>nums2[q][0]){
                ans.push_back(nums2[q]);
                q++;
            }
            else{
                ans.push_back(nums1[p]);
                p++;
            }
        }
        while(p<n){
            ans.push_back(nums1[p]);
            p++;
        }
        while(q<m){
            ans.push_back(nums2[q]);
            q++;
        }
        return ans;
    }
};