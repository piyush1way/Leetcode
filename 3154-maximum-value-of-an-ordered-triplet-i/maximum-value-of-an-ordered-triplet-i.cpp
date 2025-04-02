class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long left_max=0;
        long long max_diff=0;
        long long max_triplet=0;
        for(int i =0;i<n;i++){
            max_triplet = max(max_triplet,(max_diff)*nums[i]);
            max_diff=max(max_diff,left_max-nums[i]);
            left_max=max(left_max,(long long)nums[i]);
        }
        return max_triplet;
    }
};