class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        long long score = 0;
        while (k--) {
            int curr = q.top();
            q.pop();
            score+=curr;
            int neww = ceil(curr / 3.0);
            q.push(neww);
        }
        return score;
    }
};