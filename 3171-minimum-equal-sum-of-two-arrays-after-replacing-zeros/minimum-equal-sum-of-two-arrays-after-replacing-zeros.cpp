class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long n1 = nums1.size();
        long long n2 = nums2.size();
        long long cnt1 = 0;
        long long cnt2 = 0;
        long long sum1 = 0;
        long long sum2 = 0;

        for (int num : nums1) {
            if (num == 0) cnt1++;
            sum1 += num; 
        }
        for (int num : nums2) {
            if (num == 0) cnt2++;
            sum2 += num;
        }
        long long minsum1 = sum1 + cnt1;
        long long minsum2 = sum2 + cnt2;
        if (cnt1 == 0 && minsum2 > minsum1) {
            return -1;
        }
        if (cnt2 == 0 && minsum1 > minsum2) {
            return -1;
        }
        return max(minsum1,minsum2);
    }
};