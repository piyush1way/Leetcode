class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        
        int n = words.size();
        for (int i = 0; i < chars.size(); i++) {
            freq[chars[i] - 'a']++;
        }
        vector<int> temp=freq;
        int count = 0;
        for (int i = 0; i < n; i++) {
            string s = words[i];
            bool check = true;
            freq=temp;
            for (int j = 0; j < s.size(); j++) {
                char c = s[j];
                if (freq[c - 'a'] == 0) {
                    check = false;
                    break;
                } else {
                    freq[c - 'a']--;
                }
            }
            if (check) {
                count += s.size();
            }
        }
        return count;
    }
};