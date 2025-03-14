// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 0;
        long long high = n;
        int ans;
        while(low<=high){
            long long mid = (low+high)/2;
            if(isBadVersion(mid)==false && isBadVersion(mid+1)==true){
                ans = mid +1;
                return ans;
            }
            else if(isBadVersion(mid)==false){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};