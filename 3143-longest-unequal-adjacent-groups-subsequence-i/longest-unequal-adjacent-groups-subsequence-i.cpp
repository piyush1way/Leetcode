class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans1, ans2;
        int n = groups.size();
        
        // starting from index 0
        int ele1 = groups[0];
        ans1.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (groups[i] != ele1) {
                ele1 = groups[i];
                ans1.push_back(words[i]);
            }
        }
        
        //starting from first index where groups[j] != groups[0]
        int ele2;
        int j = 1;
        while (j < n && groups[j] == groups[0]) {
            j++;
        }
        if (j < n) {
            ele2 = groups[j];
            ans2.push_back(words[j]);
            for (int k = j + 1; k < n; k++) {
                if (groups[k] != ele2) {
                    ele2 = groups[k];
                    ans2.push_back(words[k]);
                }
            }
        }
        
        return (ans1.size() >= ans2.size()) ? ans1 : ans2;
    }
};
