class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(arr[i]%2==0){
                cnt=0;
            }
            else{
                cnt++;
                if(cnt==3){
                    return true;
                }
            }
        }
        return false;
    }
};