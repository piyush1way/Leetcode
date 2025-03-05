class Solution {
public:
    long long coloredCells(int n) {
        long long N = n; 
        return 2 * (N * N) - 2 * N + 1;
    }
};
