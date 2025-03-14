class Solution {
public:
    long long find(vector<int>& candies, long long x, long long n) {
        long long count = 0;
        for (long long i = 0; i < n; i++) {
            count = count + candies[i] / x;
        }
        return count;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        long long n = candies.size();
        for (long long i = 0; i < n; i++) {
            sum += candies[i];
        }
        long long low = 1;
        long long high = sum;
        long long ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long childs = find(candies, mid, n);
            if (childs >= k) {
                ans = mid;

                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};