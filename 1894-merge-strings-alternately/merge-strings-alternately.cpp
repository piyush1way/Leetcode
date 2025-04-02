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
        int j = 0;
        string ans = "";
        while (i < n && j < m) {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }
        while(i<n){
            ans.push_back(word1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};