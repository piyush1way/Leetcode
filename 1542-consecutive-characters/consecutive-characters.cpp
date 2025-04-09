class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            count=0;
            while(i<n && s[i]==c){
                count++;
                i++;
            }
            i--;
            maxi = max(count,maxi);
        }
        return maxi;
    }
};