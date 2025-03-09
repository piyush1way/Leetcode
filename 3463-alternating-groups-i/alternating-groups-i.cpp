class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int l =0;
        int r =2;
        int count=0;
        while(l<n){
            if(colors[l]==colors[r%n] && colors[l]!=colors[(l+1)%n]){
                count++;
            }
            l++;
            r++;
        }
        return count;
    }
};