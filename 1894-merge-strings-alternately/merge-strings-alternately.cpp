class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0) {
            return word2;
        }
        if (m == 0) {
            return word1;
        }
        int i = 0;
        string ans = "";
        while (i < n || i < m) {
            if (i < n) {
                ans.push_back(word1[i]);
            }
            if (i < m) {
                ans.push_back(word2[i]);
            }
            i++;
        }

        return ans;
    }
};