class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        long long curr_sum = 0;
        int xor_sum = 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < n) {
            curr_sum+=nums[r];
            xor_sum^=nums[r];
            if(curr_sum!=xor_sum){
                curr_sum-=nums[l];
                xor_sum^=nums[l];
                l++;
            }
            if(curr_sum==xor_sum){
                ans=r-l+1;
            }
            r++;
        }
        return ans;
    }
};