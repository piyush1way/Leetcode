class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        // move zeros to the end
        int i =0;
        int j = 0;
        while(i<n && nums[i]!=0){
            i++;
        }
        j=i+1;
        while(j<n){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                j++;
                i++;
            }
            else{
                j++;
            }
            
        }
        return nums;
    }
};