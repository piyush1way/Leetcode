class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st; 
        for (string &s : nums) {
            st.insert(stoi(s, nullptr, 2)); 
        }

        for (int i = 0; i < (1 << n); i++) {
            if (st.find(i) == st.end()) {
                return bitset<16>(i).to_string().substr(16 - n);
            }
        }

        return ""; 
    }
};
