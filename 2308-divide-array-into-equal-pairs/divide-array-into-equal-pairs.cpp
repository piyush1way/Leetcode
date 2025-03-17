class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // map<int,int>mpp;
        int freq[501];
        for(int i =1;i<=500;i++){
            freq[i]=0;
        }
        int n = nums.size();
        for(int i =0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i =1;i<=500;i++){
            if(freq[i]%2==1){
                return false;
            }
        }
        return true;
    }
};