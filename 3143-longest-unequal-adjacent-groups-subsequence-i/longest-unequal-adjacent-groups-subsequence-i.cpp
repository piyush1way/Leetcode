class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> result;
        int n = words.size();
        
        result.push_back(words[0]);
        int prev = groups[0];

        for (int i = 1; i < n; i++) {
            if (groups[i] != prev) {
                result.push_back(words[i]);
                prev = groups[i];
            }
        }
        
        return result;
    }
};
