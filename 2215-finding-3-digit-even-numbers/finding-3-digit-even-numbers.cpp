class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        set<int> seen;
        
        int n = digits.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue;
                    
                    int d1 = digits[i];
                    int d2 = digits[j];
                    int d3 = digits[k];
                    
                    if (d1 == 0) continue;     // no leading zero
                    if (d3 % 2 != 0) continue; // must be even

                    int num = d1 * 100 + d2 * 10 + d3;
                    
                    seen.insert(num);
                }
            }
        }
        
        return vector<int>(seen.begin(), seen.end());
    }
};
