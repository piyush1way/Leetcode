class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int total=0;
        for(int i = low;i<=high;i++){
            string s = to_string(i);
            if(s.size()%2==1){
                continue;
            }
            int count1=0;
            int count2=0;
            for(int i =0;i<s.size()/2;i++){
                count1+=s[i];
            }
            //second half
            for(int i =s.size()/2;i<s.size();i++){
                count2+=s[i];
            }
            if(count1==count2){
                total++;
            }
        }
        return total;
    }
};