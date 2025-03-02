class Solution {
public:

    int f(vector<int>& nums,int n){
        int currsum=0;
        int maxi=INT_MIN;
        for(int i =0;i<n;i++){
            currsum+=nums[i];
            maxi=max(currsum,maxi);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxi;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        // kadanes algo
        //maxsum
        int maxsum = f(nums,n);
        //minsum
        for(int i =0;i<n;i++){
            nums[i]=nums[i]*-1;
        }
        int minsum=f(nums,n);
        return max(maxsum,minsum);
    }
};