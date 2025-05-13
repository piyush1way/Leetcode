class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        int freq[26] = {0};

        //Count frequencies
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        //Apply t transformations
        while (t--) {
            int newFreq[26] = {0};

            for (int i = 0; i < 26; ++i) {
                if (freq[i] == 0) continue;

                if (i == 25) {
                    // 'z' -> 'a' and 'b'
                    newFreq[0] = (newFreq[0] + freq[i]) % MOD;
                    newFreq[1] = (newFreq[1] + freq[i]) % MOD;
                } else {
                    // move to next character
                    newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % MOD;
                }
            }
            for (int i = 0; i < 26; ++i) {
                freq[i] = newFreq[i];
            }
        }

        int total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + freq[i]) % MOD;
        }

        return total;
    }
};
