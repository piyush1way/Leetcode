class Solution {
public:

    int LB(int x, vector<int>& nums,int n ){
        int low = 0;
        int high = n-1;
        int ans=n;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int UB(int x, vector<int>& nums,int n ){
        int low = 0;
        int high = n-1;
        int ans=n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int x = LB(0,nums,n);
        int y = UB(0,nums,n);
        return max(y, n - x);


    }
};