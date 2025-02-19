class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int m = s.size();

        unordered_map<char, string> mpp;
        unordered_map<string, char> mpp2;
        int j = 0;
        for (int i = 0; i < n; i++) {
            char c = pattern[i];
            string temp;
            while (j < m && s[j] != ' ') {
                temp += s[j];
                j++;
            }
            if (mpp.find(c) != mpp.end()) {
                string temp2 = mpp[c];
                if (temp != temp2) {
                    return 0;
                }
            } else {
                mpp[c] = temp;
            }
            if (mpp2.find(temp) != mpp2.end()) {
                char a = mpp2[temp];
                if (a != c) {
                    return 0;
                }
            } else {
                mpp2[temp] = c;
            }
            // remove spaces
            while (j < m && s[j] == ' ') {
                j++;
            }
            if(j==m && i<n-1){
                return 0;
            }
        }
        if(j<m){
            return false;
        }
        return 1;
    }
};