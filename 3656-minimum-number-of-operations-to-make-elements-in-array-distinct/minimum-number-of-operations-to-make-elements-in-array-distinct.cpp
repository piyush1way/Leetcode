class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        reverse(nums.begin(), nums.end()); 

        int operations = 0;

        while (true) {
            bool hasDuplicate = false;

            for (auto& p : freq) {
                if (p.second > 1) {
                    hasDuplicate = true;
                    break;
                }
            }

            if (!hasDuplicate) break;

            for (int i = 0; i < 3 && !nums.empty(); i++) {
                int val = nums.back();
                freq[val]--;
                if (freq[val] == 0) {
                    freq.erase(val);
                }
                nums.pop_back();
            }

            operations++;
        }

        return operations;
    }
};
