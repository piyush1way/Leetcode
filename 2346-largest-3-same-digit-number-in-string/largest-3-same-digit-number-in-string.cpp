class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        vector<int> freq(10, 0);
        string temp = "";
        string ans = "";
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if (!freq[digit]) {
                fill(freq.begin(), freq.end(), 0);
                temp.clear();
                freq[digit]++;
                temp += num[i];
            } else {
                freq[digit]++;
                temp += num[i];
            }
            if (temp.size() == 3) {
                if (ans.empty() || ans < temp) {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};