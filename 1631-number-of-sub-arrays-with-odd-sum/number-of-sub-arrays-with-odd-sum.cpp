class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 +7;
        int n = arr.size();
        int evencnt = 1;
        int oddcnt = 0;
        int prefix = 0;
        int total=0;
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            if (prefix % 2 == 1) {
                total = (total + evencnt)%MOD;
                oddcnt++;
            } else {
                total = (total + oddcnt)%MOD;
                evencnt++;
            }
        }
        return total;
    }
};