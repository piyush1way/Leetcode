class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n==1 && nums[0]>=target){
            return 1;
        }
        
        int minlen = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = nums[0];
        while (j < n) {
            while (sum < target && j < n) {
                j++;
                if (j < n)
                    sum += nums[j];
            }
            if (sum >= target) {
                minlen = min(minlen, j - i + 1);
            }
            sum = sum - nums[i];
            i++;
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
    }
    
};