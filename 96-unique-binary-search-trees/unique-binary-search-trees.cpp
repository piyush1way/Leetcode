class Solution {
public:
    long long binomialCoeff(int n, int k) {
        long long res = 1;
        for (int i = 0; i < k; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }

    long long catalan(int n) { return binomialCoeff(2 * n, n) / (n + 1); }
    int numTrees(int n) {
        return catalan(n);
    }
};