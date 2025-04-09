class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int maxi1 = 0;
        int maxi2 = 0;
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            zeros = 0;
            ones = 0;
            if (c == '0') {
                while (i < n && s[i] == c) {
                    zeros++;
                    i++;
                }
                i--;
                maxi1 = max(zeros, maxi1);
            } else {
                while (i < n && s[i] == c) {
                    ones++;
                    i++;
                }
                i--;
                maxi2 = max(ones, maxi2);
            }
        }
        return maxi2 > maxi1;
    }
};