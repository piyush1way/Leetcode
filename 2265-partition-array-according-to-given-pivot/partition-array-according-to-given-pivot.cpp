class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        int count=0; //cnt pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans.push_back(nums[i]);
                visited[i] = true;
            }
            if(pivot==nums[i]){
                count++;
                visited[i]=true;
            }
        }
        while(count--){
            ans.push_back(pivot);

        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(nums[i]);
                visited[i] = true;
            }
        }
        return ans;
    }
};