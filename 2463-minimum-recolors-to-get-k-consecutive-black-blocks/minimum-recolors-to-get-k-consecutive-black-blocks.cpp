class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 0, r = 0;
        int blacks = 0, maxBlacks = 0;
        while (r < n) {
            if (blocks[r] == 'B')
                blacks++;

            if (r - l + 1 == k) {
                maxBlacks = max(maxBlacks, blacks);
                if (blocks[l] == 'B')
                    blacks--; 
                l++;          
            }
            r++;
        }

        return k - maxBlacks; 
    }
};